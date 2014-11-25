/* Fast_DynamicInitializer.c
 *
 *  Generated on Nov 18 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast_DynamicInitializer.h"
#include "Fast__meta.h"


/* $header() */
#include "Fast__api.h"
#include "Fast_Parser.h"
#include "Fast_Expression.h"

Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
void Fast_Parser_warning(Fast_Parser _this, char* fmt, ...);

/* Add instructions that set sequence size */
Fast_Expression Fast_Initializer_setSequenceSize(Fast_DynamicInitializer _this, Fast_Expression expression, Fast_Expression size) {
    db_function sequenceSize;
    Fast_String sequenceSizeString;
    Fast_MemberExpr memberExpr;
    Fast_Call sequenceSizeCall;
    
    DB_UNUSED(_this);
    
    sequenceSize = db_resolve_ext(_this, NULL, "sequence::size(uint32)", FALSE, "Insert size-function for setting sequence size");
    sequenceSizeString = Fast_String__create(db_strdup(db_nameof(sequenceSize)));
    db_free_ext(_this, sequenceSize, "Free size-function for setting sequence size");
    
    /* Create member-expression with call statement and insert to ast */
    memberExpr = Fast_MemberExpr__create(expression, Fast_Expression(sequenceSizeString));
    sequenceSizeCall = Fast_Call__create(Fast_Expression(memberExpr), size);
    Fast_Parser_addStatement(yparser(), Fast_Node(sequenceSizeCall));
    
    /* Garbagecollection of objects */
    Fast_Parser_collect(yparser(), sequenceSizeString);
    Fast_Parser_collect(yparser(), sequenceSizeCall);
    Fast_Parser_collect(yparser(), memberExpr);
    
    return sequenceSizeCall->arguments;
}

db_int16 Fast_Initializer_assign(Fast_DynamicInitializer _this, Fast_Expression lvalue, Fast_Expression rvalue) {
    DB_UNUSED(_this);
    if (rvalue) {
        Fast_BinaryExpr expr = Fast_BinaryExpr__create(lvalue, rvalue, DB_ASSIGN);
        Fast_Parser_addStatement(yparser(), Fast_Node(expr));
        Fast_Parser_collect(yparser(), expr);
    }
    return 0;
}

db_int16 Fast_Initializer_append(Fast_DynamicInitializer _this, Fast_Expression lvalue, Fast_Expression rvalue) {
    DB_UNUSED(_this);
    Fast_Expression member;
    Fast_String operation;
    Fast_Expression statement;

    operation = Fast_String__create("append");
    
    /* Create memberexpression */
    member = Fast_Expression(Fast_MemberExpr__create(lvalue, Fast_Expression(operation)));
    if (!member) {
        /* TODO: free resources */
        goto error;
    }
    
    /* Create call-expression */
    if (!(statement = Fast_Expression(Fast_Call__create(member, rvalue)))) {
        goto error;
    }
    
    Fast_Parser_addStatement(yparser(), Fast_Node(statement));
    
    /* Garbage collect objects */
    Fast_Parser_collect(yparser(), operation);
    Fast_Parser_collect(yparser(), member);
    Fast_Parser_collect(yparser(), statement);

    return 0;
error:
    return -1;
}

db_int16 Fast_Initializer_clear(Fast_DynamicInitializer _this, Fast_Expression lvalue) {
    DB_UNUSED(_this);

    Fast_Expression member;
    Fast_String operation;
    Fast_Expression statement;
    
    operation = Fast_String__create("clear");
    
    /* Create memberexpression */
    member = Fast_Expression(Fast_MemberExpr__create(lvalue, Fast_Expression(operation)));
    if (!member) {
        /* TODO: free resources */
        goto error;
    }
    
    /* Create call-expression */
    if (!(statement = Fast_Expression(Fast_Call__create(member, NULL)))) {
        goto error;
    }
    
    Fast_Parser_addStatement(yparser(), Fast_Node(statement));
    
    /* Garbage collect objects */
    Fast_Parser_collect(yparser(), operation);
    Fast_Parser_collect(yparser(), member);
    Fast_Parser_collect(yparser(), statement);
    
    return 0;
error:
    return -1;
}

/* Assign or add value to expression */
Fast_Expression Fast_Initializer_expr(Fast_DynamicInitializer _this, db_uint8 variable, Fast_Expression v) {
	Fast_Expression result, base;
    db_uint16 fp = Fast_Initializer(_this)->fp;
	Fast_InitializerFrame *frame = &Fast_Initializer(_this)->frames[fp?fp-1:0];
	Fast_DynamicInitializerFrame *baseFrame = &(_this->frames[fp?fp-1:0]);
    Fast_InitializerFrame *thisFrame = &Fast_Initializer(_this)->frames[fp];
	
    result = 0;
    
	base = baseFrame->expr[variable];
	if (!base) {
		Fast_Parser_error(yparser(), "parser error: base is zero in offset calculation");
		goto error;
	}
    
	/* Switch on current type */
	switch(frame->type->kind) {
        case DB_PRIMITIVE:
            result = base;
            break;
        case DB_COMPOSITE:
            if (fp) {
                Fast_String memberString = Fast_String__create(db_nameof(thisFrame->member));
                result = Fast_Expression(Fast_MemberExpr__create(base, Fast_Expression(memberString)));
                Fast_Parser_collect(yparser(), result);
                Fast_Parser_collect(yparser(), memberString);
            } else {
                result = base;
            }
            Fast_Initializer_assign(_this, result, v);
            break;
        case DB_COLLECTION: {
            if (fp) {
                switch(db_collection(frame->type)->kind) {
                case DB_LIST:
                    Fast_Initializer_append(_this, base, v);
                case DB_SEQUENCE:
                case DB_ARRAY: {
                    Fast_Integer index = Fast_Integer__create(thisFrame->location);
                    result = Fast_Expression(Fast_ElementExpr__create(base, Fast_Expression(index)));
                    Fast_Parser_collect(yparser(), result);
                    Fast_Parser_collect(yparser(), index);
                    if (db_collection(frame->type)->kind != DB_LIST) {
                        Fast_Initializer_assign(_this, result, v);
                    }
                    break;
                }
                case DB_MAP:
                    if (!thisFrame->isKey) {
                        result = Fast_Expression(Fast_ElementExpr__create(base, Fast_Expression(_this->frames[fp].keyExpr[variable])));
                        Fast_Parser_collect(yparser(), result);
                        thisFrame->isKey = FALSE;
                        Fast_Initializer_assign(_this, result, v);
                    }
                    break;
                }
            } else {
                result = base;
            }
            break;
        }
        default: {
            if (frame->type->reference) {
                result = base;
            } else {
                db_id id;
                Fast_Parser_error(yparser(), "invalid initializer type '%s'", db_fullname(frame->type, id));
                abort();
            }
            break;
        }
	}
    
	return result;
error:
	return 0;

}

/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::DynamicInitializer::construct(DynamicInitializer object) */
db_int16 Fast_DynamicInitializer_construct(Fast_DynamicInitializer object) {
/* $begin(::hyve::Fast::DynamicInitializer::construct) */
	db_int8 variable;
    
    /* Copy offsets of variables into frames */
	for(variable=0; variable<Fast_Initializer(object)->variableCount; variable++) {
        Fast_Expression var = Fast_Initializer(object)->variables[variable].object;
        db_set_ext(object, &object->frames[0].expr[variable], var, ".frames[0].expr[variable]");
	}
    
    return Fast_Initializer_construct(Fast_Initializer(object));
/* $end */
}

/* ::hyve::Fast::DynamicInitializer::define() */
db_int16 Fast_DynamicInitializer_define(Fast_DynamicInitializer _this) {
/* $begin(::hyve::Fast::DynamicInitializer::define) */
	db_int8 variable;
    db_type t = Fast_Initializer_type(Fast_Initializer(_this));
    
    /* Copy offsets of variables into frames */
    if (!_this->assignValue && (t->kind == DB_COMPOSITE)) {
        for(variable=0; variable<Fast_Initializer(_this)->variableCount; variable++) {
            Fast_Define defineExpr = Fast_Define__create(_this->frames[0].expr[variable]);
            Fast_Parser_addStatement(yparser(), Fast_Node(defineExpr));
            Fast_Parser_collect(yparser(), defineExpr);
        }
        Fast_Initializer_define_v(Fast_Initializer(_this));
    }

    return 0;
/* $end */
}

/* ::hyve::Fast::DynamicInitializer::pop() */
db_int16 Fast_DynamicInitializer_pop(Fast_DynamicInitializer _this) {
/* $begin(::hyve::Fast::DynamicInitializer::pop) */
    db_uint8 fp = Fast_Initializer(_this)->fp;

    if (_this->frames[fp-1].sequenceSize) {
        Fast_Integer(_this->frames[fp-1].sequenceSize)->value = Fast_Initializer(_this)->frames[fp].location;
    }

    return Fast_Initializer_pop_v(Fast_Initializer(_this));
/* $end */
}

/* ::hyve::Fast::DynamicInitializer::push() */
db_int16 Fast_DynamicInitializer_push(Fast_DynamicInitializer _this) {
/* $begin(::hyve::Fast::DynamicInitializer::push) */
	db_uint8 variable;
    db_type t = Fast_Initializer_currentType(Fast_Initializer(_this));
    db_uint8 fp = Fast_Initializer(_this)->fp;
    Fast_Node expr = Fast_Node(_this->frames[fp].expr[0]);
    db_bool isAnonymousLocal = expr && 
        (expr->kind == FAST_Variable) && (Fast_Variable(expr)->kind == FAST_Local) && (*Fast_Local(expr)->name == '<');
    
    /* Check if push is allowed */
    if (!(!fp && _this->assignValue) && (t->reference && !isAnonymousLocal)) {
        db_id id;
        Fast_Parser_error(yparser(), "unexpected initializer scope for value of referencetype '%s'", db_fullname(t, id));
        goto error;
    }

    /* Obtain expression for all variables being initialized */
    for(variable=0; variable<Fast_Initializer(_this)->variableCount; variable++) {
        db_set_ext(_this, &_this->frames[fp].expr[variable], Fast_Initializer_expr(_this, variable, NULL), ".frames[fp].expr[variable]");
    }

    if (Fast_Initializer_push_v(Fast_Initializer(_this))) {
        goto error;
    }
    
    /* If scope contains contents of a sequence insert operation to set sequence-size. Because size is not known beforehand,
     * cache the expression that contains the size. This will be set to it's final value when sequence-scope is pop'd. */
    if ((t->kind == DB_COLLECTION) && (db_collection(t)->kind == DB_SEQUENCE)) {
        Fast_Integer size = Fast_Integer__create(0);
        Fast_Parser_collect(yparser(), size);
        
        /* Cast the size to uint32 so that the expression won't be replaced by a cast when it is inserted in the argumentlist
        * of sequence::size(uint32). This way there is no need for keeping track of a size-expression per variable. Note: the
        * native type of a Fast::Integer is uint64. */
        size = Fast_Integer(Fast_Expression_cast(Fast_Expression(size), db_type(db_uint32_o)));
        db_set_ext(_this, &_this->frames[fp].sequenceSize, size, ".frames[fp].sequenceSize");
        
        for(variable=0; variable<Fast_Initializer(_this)->variableCount; variable++) {
            Fast_Initializer_setSequenceSize(_this, _this->frames[fp].expr[variable], Fast_Expression(size));
        }
    } else if ((t->kind == DB_COLLECTION) && (db_collection(t)->kind == DB_LIST)) {
        if (_this->assignValue) {
            /* If assigning a complex value to a list, clear list first */
            for(variable=0; variable<Fast_Initializer(_this)->variableCount; variable++) {
                Fast_Initializer_clear(_this, _this->frames[fp].expr[variable]);
            }
        }
    } else {
        db_set_ext(_this, &_this->frames[fp].sequenceSize, NULL, ".frames[fp].sequenceSize");
    }
    
    return 0;
error:
    return -1;
/* $end */
}

/* ::hyve::Fast::DynamicInitializer::value(Expression v) */
db_int16 Fast_DynamicInitializer_value(Fast_DynamicInitializer _this, Fast_Expression v) {
/* $begin(::hyve::Fast::DynamicInitializer::value) */
	db_uint32 variable;
    db_uint32 fp = Fast_Initializer(_this)->fp;
    db_type type = Fast_Initializer_currentType(Fast_Initializer(_this));
    
    if (!type) {
        db_id id;
        Fast_Parser_error(yparser(), "excess elements in initializer of type '%s'",
            db_fullname(Fast_ObjectBase(Fast_Expression(_this)->type)->value, id));
        goto error;
    }

    /* Validate whether expression type matches current type of initializer */
    if (!db_type_compatible(type, Fast_Expression_getType_type(v, type))) {
        db_id id, id2;
        Fast_Parser_error(yparser(), "type '%s' invalid here (expected '%s')", 
            db_fullname(Fast_Expression_getType(v), id), db_fullname(type, id2));
        goto error;
    }
    
	/* Serialize value to all variables being initialized */
	for(variable=0; variable<Fast_Initializer(_this)->variableCount; variable++) {
        if (Fast_Initializer(_this)->frames[fp].isKey) {
            db_set(&_this->frames[fp].keyExpr[variable], v);
        } else {
            Fast_Initializer_expr(_this, variable, v);
        }
    }
    
	return Fast_Initializer_next(Fast_Initializer(_this));
error:
    return -1;
/* $end */
}