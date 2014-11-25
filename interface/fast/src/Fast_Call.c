/* Fast_Call.c
 *
 *  Generated on Nov 18 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_Call.h"
#include "Fast__meta.h"


/* $header() */
#include "Fast__api.h"
#include "Fast_Parser.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);

/* Insert implicit casts when argument-expressions do not match */
db_int16 Fast_Call_insertCasts(Fast_Call _this) {
	db_iter argumentIter;
	Fast_Expression argument;
	db_uint32 i = 0;
	db_function function;
	db_type parameterType, argumentType;

	function = _this->actualFunction;
	if (_this->arguments) {
        db_ll arguments = Fast_Expression_toList(_this->arguments);
        argumentIter = db_llIter(arguments);
        while(db_iterHasNext(&argumentIter)) {
            argument = db_iterNext(&argumentIter);
            parameterType = function->parameters.buffer[i].type->real;
            argumentType = Fast_Expression_getType(argument);

            if (function->parameters.buffer[i].passByReference) {
            	if (!argument->isReference) {
            		Fast_Parser_error(yparser(), "cannot pass non-reference value as reference");
            		goto error;
            	}
            }
            
            /* If both types are not equal, insert cast */
            if (parameterType != argumentType) {
                Fast_Expression expr;

                /* Any types are handled in the translation to the target representation. It is often
                 * more efficient to push a value as any than to first cast it to any and then push it. */
                if (parameterType->kind != DB_ANY) {
                    expr = Fast_Expression_cast(argument, parameterType);
                    if (expr) {
                        db_keep_ext(_this, expr, "Keep cast-expression as argument");
                        db_llReplace(arguments, argument, expr);
                        db_free_ext(_this, argument, "Free old (uncasted) expression from argumentlist");
                    }
                }
            }

            i++;
        }
        db_set(&_this->arguments, Fast_Expression_fromList(arguments));
        Fast_Expression_cleanList(arguments);
    }

	return 0;
error:
	return -1;
}

/* Resolve correct function based on argumentlist */
db_int16 Fast_Call_resolveActual(Fast_Call _this, db_function function) {
	db_string signature;
	db_id functionName;
	db_iter argumentIter;
	Fast_Expression argument;
	db_type argumentType;
	db_function overloaded;
    
	/* Get name from function signature */
	db_signatureName(db_nameof(function), functionName);

	/* Build request-signature */
	signature = db_signatureOpen(functionName);

	if (_this->arguments) {
        db_ll arguments = Fast_Expression_toList(_this->arguments);
        argumentIter = db_llIter(arguments);
        while(db_iterHasNext(&argumentIter)) {
            argument = db_iterNext(&argumentIter);
            argumentType = Fast_Expression_getType(argument);

            /* If there is no type and the argument is an initializer, insert a wildcard */
            if (!argumentType && (Fast_Node(argument)->kind == FAST_Initializer)) {
            	signature = db_signatureAddWildcard(signature, FALSE);

        	/* If function is overloaded, you have to explicitly specify whether an argument is a reference or not */
            } else if (function->overloaded) {
            	signature = db_signatureAdd(signature, db_typedef(argumentType), argument->forceReference);
            } else {
            	signature = db_signatureAdd(signature, db_typedef(argumentType), argument->isReference);
            }
        }
        Fast_Expression_cleanList(arguments);
	}

	/* Store signature for when a method needs to be resolved at runtime */
	signature = _this->signature = db_signatureClose(signature);

	/* If function is not a method, do a resolve on the signature */
	switch(db_procedure(db_typeof(function))->kind) {
	case DB_FUNCTION:
	    /* Resolve overloaded function, allow casting */
		overloaded = db_resolve_ext(NULL, db_parentof(function), signature, TRUE, NULL);
		if (overloaded) {
			_this->actualFunction = overloaded;
		} else {
			db_id id;
			Fast_Parser_error(yparser(), "no function in scope '%s' that matches signature '%s'",
					db_fullname(db_parentof(function), id), _this->signature);
			goto error;
		}
		break;
	case DB_METHOD:
		db_assert(db_class_instanceof(db_interface_o, db_parentof(function)), "method not declared in interface - impossible");

		overloaded = (db_function)db_interface_resolveMethod(db_parentof(function), signature);
		if (overloaded) {
			/* If method is virtual, it needs to be resolved at runtime */
			if (!db_method(overloaded)->virtual) {
				_this->actualFunction = overloaded;
				db_keep_ext(_this, overloaded, "Keep actualFunction for call-expression (method)");
			}
		} else {
			db_id id;
			Fast_Parser_error(yparser(), "no method in interface '%s' that matches signature '%s'",
					db_fullname(db_parentof(function), id), _this->signature);
			goto error;
		}
		break;
	case DB_METAPROCEDURE: {
	    db_type lvalueType = Fast_Expression_getType(Fast_MemberExpr(_this->function)->lvalue);
		overloaded = (db_function)db_type_resolveProcedure(lvalueType, signature);
		if (overloaded) {
			/* If method is virtual, it needs to be resolved at runtime */
			_this->actualFunction = overloaded;
			db_keep_ext(_this, overloaded, "Keep actualFunction for call-expression (metaprocedure)");

			/* Validate whether metaprocedure only accepts references, and whether lvalue is a reference */
			if(db_metaprocedure(overloaded)->referenceOnly && !Fast_MemberExpr(_this->function)->lvalue->isReference) {
				db_id id;
				Fast_Parser_error(yparser(), "metaprocedure '%s' accepts only reference values",
					db_fullname(overloaded, id));
				goto error;
			}
		} else {
			db_id id;
			Fast_Parser_error(yparser(), "no method in interface '%s' that matches signature '%s'",
					db_fullname(db_parentof(function), id), _this->signature);
			goto error;
		}
		break;
	}
	default:
		Fast_Parser_error(yparser(), "cannot call delegates, callbacks or observers directly");
		break;
	}

	/* Walk arguments, insert casts if required */
	if (Fast_Call_insertCasts(_this)) {
		goto error;
	}

	return 0;
error:
	return -1;
}
/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::Call::construct(Fast::Call object) */
db_int16 Fast_Call_construct(Fast_Call object) {
/* $begin(::hyve::Fast::Call::construct) */
	db_type functionType;
	db_function function = NULL;
    Fast_nodeKind kind = Fast_Node(object->function)->kind;

	Fast_Node(object)->kind = FAST_Call;

	/* Retrieve returnType */
	switch(kind) {
	case FAST_Variable:
		switch(Fast_Variable(object->function)->kind) {
		case FAST_Object:
			/* Verify that called object is a function */
			functionType = Fast_Expression_getType(object->function);
			if (db_class_instanceof(db_procedure_o, functionType)) {
				function = Fast_ObjectBase(object->function)->value;
			} else {
				Fast_Parser_error(yparser(), "called object is not a function");
				goto error;
			}
			break;
		case FAST_Local: /* Recursive call */
			if (Fast_Local(object->function)->kind == FAST_LocalReturn) {
				Fast_Block block = yparser()->block;
				/* Find function that corresponds with current block */
				do {
					function = block->function;
				}while(!function && (block = block->parent));

				if (function) {
					/* If this is a recursive call to a method, replace the return-variable expression
					 * with a member-expression which includes the 'this'-variable. */
					if (db_procedure(db_typeof(function))->kind == DB_METHOD) {
						Fast_MemberExpr memberExpr;
						Fast_String methodStr;
						Fast_Expression thisVar = Fast_Parser_lookup(yparser(), "this", NULL);

						methodStr = Fast_String__create(db_nameof(function));
						memberExpr = Fast_MemberExpr__create(thisVar, Fast_Expression(methodStr));
						Fast_Parser_collect(yparser(), methodStr);
						Fast_Parser_collect(yparser(), memberExpr);
						db_set_ext(object, &object->function, memberExpr,
								"Replace returnVariable with member-expression for method call");
					}
				} else {
					Fast_Parser_error(yparser(), "parser error: found returnvariable in non-function scope");
					goto error;
				}
			} else {
				Fast_Parser_error(yparser(), "variable '%s' is not a callable object", Fast_Local(object->function)->name);
				goto error;
			}
			break;
		default:
			/* TODO: Variable function */
			Fast_Parser_error(yparser(), "run-time type resolving not yet supported");
			goto error;
			break;
		}
		break;
	case FAST_Member:
		/* Verify that called object is a function */
		functionType = db_typeof(Fast_MemberExpr(object->function)->member)->real;
		if (db_class_instanceof(db_procedure_o, functionType)) {
			function = Fast_MemberExpr(object->function)->member;
		} else {
			db_id id;
			Fast_Parser_error(yparser(), "called object is not a function (type=%s)",
					db_fullname(functionType, id));
			goto error;
		}
		break;
	default:
		Fast_Parser_error(yparser(), "expression not supported for call (%s)", db_nameof(db_enum_constant(Fast_nodeKind_o, kind)));
		goto error;
		break;
	}

	/* Resolve actual method, based on arguments (overloading), taking into account inheritance (virtual methods) */
	if (Fast_Call_resolveActual(object, function)) {
		goto error;
	}

	db_set(&Fast_Expression(object)->type, Fast_Variable(Fast_Object__create(object->actualFunction->returnType)));
    Fast_Parser_collect(yparser(), Fast_Expression(object)->type);
	Fast_Expression(object)->isReference = 
		object->actualFunction->returnsReference || object->actualFunction->returnType->real->reference;

    return 0;
error:
	return -1;
/* $end */
}

/* virtual ::hyve::Fast::Call::hasSideEffects() */
db_bool Fast_Call_hasSideEffects(Fast_Call _this) {
    static db_uint32 _methodId;
    db_method _method;
    db_bool _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "hasSideEffects()");
    }
    db_assert(_methodId, "virtual method 'hasSideEffects()' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::hasSideEffects()@%d'", db_nameof(_this), _methodId);

    /* Call method directly if it's a C-function. */
    if (_method->_parent.kind == DB_PROCEDURE_CDECL) {
        db_assert(_method->_parent.impl, "missing implementation for '%s::hasSideEffects()'.", db_nameof(_this));
        _result = ((db_bool(*)(Fast_Call))_method->_parent.impl)(_this);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this);
    }
    
    return _result;
}

/* ::hyve::Fast::Call::hasSideEffects() */
db_bool Fast_Call_hasSideEffects_v(Fast_Call _this) {
/* $begin(::hyve::Fast::Call::hasSideEffects) */
    DB_UNUSED(_this);
    return TRUE;
/* $end */
}

/* virtual ::hyve::Fast::Call::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Call_toIc(Fast_Call _this, db_icProgram program, db_icStorage storage, db_bool stored) {
    static db_uint32 _methodId;
    db_method _method;
    db_ic _result;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)");
    }
    db_assert(_methodId, "virtual method 'toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)@%d'", db_nameof(_this), _methodId);

    /* Call method directly if it's a C-function. */
    if (_method->_parent.kind == DB_PROCEDURE_CDECL) {
        db_assert(_method->_parent.impl, "missing implementation for '%s::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.", db_nameof(_this));
        _result = ((db_ic(*)(Fast_Call, db_icProgram , db_icStorage , db_bool ))_method->_parent.impl)(_this, program, storage, stored);
    } else {
        /* Function is implemented in another language. */
        db_call(db_function(_method), &_result, _this, program, storage, stored);
    }
    
    return _result;
}

/* ::hyve::Fast::Call::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Call_toIc_v(Fast_Call _this, db_icProgram program, db_icStorage storage, db_bool stored) {
/* $begin(::hyve::Fast::Call::toIc) */
	db_icStorage function, result = NULL, argumentStorage = NULL;
	db_uint32 argumentStorageCount = 0;
	db_ic argumentIc = NULL;
	db_icOp call;
	db_iter argumentIter;
	Fast_Expression argument;
	db_icOp *pushIcs = NULL;
	db_int32 argumentId = 0, argumentCount = 0;
	db_type _thisType = Fast_Expression_getType(Fast_Expression(_this));
    db_ll arguments = NULL;
	DB_UNUSED(stored);
	DB_UNUSED(storage);
    
	if (storage && (storage->type == _thisType)) {
		result = storage;
	} else {
		result = (db_icStorage)db_icProgram_accumulatorPush(program, Fast_Node(_this)->line, _thisType, _this->actualFunction->returnsReference);
	}
    
    /* Signal that storage will hold return value */
    result->holdsReturn = TRUE;
    
    if (_this->arguments) {
        arguments = Fast_Expression_toList(_this->arguments);
    }
	if (arguments) {
		argumentCount = db_llSize(arguments);
    }
    

	/* Obtain function */
	function = (db_icStorage)db_icObject__create(program, Fast_Node(_this)->line, _this->actualFunction);
    
	/* Push 'this' if function is a method or metaprocedure */
	switch(db_procedure(db_typeof(_this->actualFunction))->kind) {
	case DB_METHOD:
	case DB_METAPROCEDURE: {
		db_ic thisIc;
		db_assert(Fast_Node(_this->function)->kind == FAST_Member, "method-call expects member expression");
		thisIc = Fast_Node_toIc(Fast_Node(Fast_MemberExpr(_this->function)->lvalue), program, NULL, TRUE);
		argumentCount += 1;
	    pushIcs = alloca(argumentCount * sizeof(db_icOp));
	    pushIcs[argumentId] = db_icOp__create(program, Fast_Node(_this)->line, DB_IC_PUSH, (db_icValue)thisIc, NULL, NULL);
	    pushIcs[argumentId]->s1Deref = DB_IC_DEREF_ADDRESS;
	    argumentId++;

	    /* If function is a metaprocedure, push 'this' as an any value, conform metaprocedure signatures */
	    if (db_procedure(db_typeof(_this->actualFunction))->kind == DB_METAPROCEDURE) {
	    	pushIcs[argumentId-1]->s1Any = TRUE;
	    }
		break;
	}
	default:
		if (_this->arguments) {
			pushIcs = alloca(argumentCount * sizeof(db_icOp));
		}
		break;
	}

	/* Push arguments */
	if (_this->arguments) {
	    db_uint32 i = 0;

	    /* Temporary storage for push-instructions required for pushing the arguments of this function */
        argumentIter = db_llIter(arguments);
        while(db_iterHasNext(&argumentIter)) {
            db_type paramType, exprType;
            argument = db_iterNext(&argumentIter);
            if (!argumentStorage ||
              (argumentIc == (db_ic)argumentStorage) ||
              (Fast_Expression_getType(argument) != argumentStorage->type)) {
                argumentStorage = (db_icStorage)db_icProgram_accumulatorPush(
                	program, 
                	Fast_Node(_this)->line, 
                	Fast_Expression_getType(argument),
                	argument->isReference);
                argumentStorageCount++;
            }
            argumentIc = Fast_Node_toIc(Fast_Node(argument), program, argumentStorage, TRUE);
            pushIcs[argumentId] = db_icOp__create(program, Fast_Node(_this)->line, DB_IC_PUSH, (db_icValue)argumentIc, NULL, NULL);
            argumentId++;

            /* If parameterType is any and argument is not, push value as any */
            paramType = _this->actualFunction->parameters.buffer[i].type->real;
            exprType = Fast_Expression_getType(argument);

            if (paramType->kind == DB_ANY) {
                if (exprType && (exprType->kind != DB_ANY)) {
                    pushIcs[argumentId-1]->s1Any = TRUE;
                } else if (!exprType) {
                    pushIcs[argumentId-1]->s1Any = TRUE;
                }
                pushIcs[argumentId-1]->s1Deref = DB_IC_DEREF_ADDRESS;
            } else {
                if (!exprType) {
                    exprType = paramType;
                }
            	if (_this->actualFunction->parameters.buffer[i].passByReference || (paramType->reference && !exprType->reference)) {
            		pushIcs[argumentId-1]->s1Deref = DB_IC_DEREF_ADDRESS;
            	} else {
            		pushIcs[argumentId-1]->s1Deref = DB_IC_DEREF_PUSH;
            	}
            }
            i++;
        }
	}

    /* Add push-instructions just before doing the call so it doesn't interfere with call-expressions in
     * the argument list */
    for(argumentId = 0; argumentId < argumentCount; argumentId++) {
        db_icProgram_addIc(program, (db_ic)pushIcs[argumentId]);
    }

	/* Do call */
	call = db_icOp__create(program, Fast_Node(_this)->line, DB_IC_CALL, (db_icValue)result, (db_icValue)function, NULL);
	db_icProgram_addIc(program, (db_ic)call);

	if (_this->actualFunction->returnsReference) {
		call->s1Deref = DB_IC_DEREF_ADDRESS;
	}

	while(argumentStorageCount) {
	    db_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
	    argumentStorageCount--;
	}

	if (storage != result) {
		db_icProgram_accumulatorPop(program, Fast_Node(_this)->line);
	}
    
    Fast_Expression_cleanList(arguments);
    
	return (db_ic)result;
/* $end */
}