/* cx_delegate.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* ::cortex::lang::delegate::bind(function object) */
cx_int16 cx_delegate_bind(cx_function object) {
/* $begin(::cortex::lang::delegate::bind) */
    cx_object parent = cx_parentof(object);

    if (cx_class_instanceof(cx_interface_o, cx_typeof(parent))) {
        cx_interface type = cx_interface(cx_typeof(parent));
        cx_id functionName;
        cx_member m = NULL;

        /* Get function name, lookup delegate, assign function */
        cx_signatureName(cx_nameof(object), functionName);
        if (cx_checkState(cx_type_o, CX_DEFINED) && (m = cx_interface_resolveMember(type, functionName)) &&
            (m->type->kind == CX_COMPOSITE) && (cx_interface(m->type)->kind == CX_DELEGATE)) {
            if (cx_delegate_instanceof(cx_delegate(m->type), object)) {
                /* Bind instance of function is a method */
                if (cx_procedure(cx_typeof(object))->kind == CX_METHOD) {
                    cx_set(&((cx_delegatedata *) CX_OFFSET(parent, m->offset))->instance, parent);
                }
                /* Bind procedure */
                cx_set(&((cx_delegatedata *) CX_OFFSET(parent, m->offset))->procedure, object);    
            } else {
                /* If there is a member that corresponds to a delegate but has a non matching
                 * signature, always report error */
                cx_id id1, id2;
                cx_error("member '%s' of delegate type '%s' does not match signature of '%s'",
                    cx_nameof(m), cx_fullname(m->type, id1), cx_fullname(object, id2));
                goto error;
            }
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::lang::delegate::castable(type type) */
cx_bool cx_delegate_castable_v(cx_delegate _this, cx_type type) {
/* $begin(::cortex::lang::delegate::castable) */
    return cx_delegate_compatible_v(_this, type);
/* $end */
}

/* ::cortex::lang::delegate::compatible(type type) */
cx_bool cx_delegate_compatible_v(cx_delegate _this, cx_type type) {
/* $begin(::cortex::lang::delegate::compatible) */
    cx_bool result = FALSE;
    CX_UNUSED(_this);

    if((type->kind == CX_COMPOSITE) && (cx_interface(type)->kind == CX_DELEGATE)) {
        cx_uint32 i;
        result = TRUE;

        /* Validate returntype */
        if((_this->returnType != cx_delegate(type)->returnType) || (_this->returnsReference != cx_delegate(type)->returnsReference)) {
            result = FALSE;
        }

        /* Validate number of parameters */
        if(_this->parameters.length != cx_delegate(type)->parameters.length) {
            result = FALSE;
        }

        /* Validate parameters */
        for(i = 0; !result && (i < _this->parameters.length); i++) {
            if(_this->parameters.buffer[i].type != cx_delegate(type)->parameters.buffer[i].type) {
                result = FALSE;
            }
            if(_this->parameters.buffer[i].passByReference != cx_delegate(type)->parameters.buffer[i].passByReference) {
                result = FALSE;
            }
        }   
    } else if ((type->kind == CX_COMPOSITE) && (cx_interface(type)->kind == CX_PROCEDURE)) {
        result = TRUE;
    }

    return result;
/* $end */
}

/* ::cortex::lang::delegate::init() */
cx_int16 cx_delegate_init(cx_delegate _this) {
/* $begin(::cortex::lang::delegate::init) */
    cx_int16 result;

    cx_interface(_this)->base = cx_interface(cx_delegatedata_o);

    result = cx_struct_init(cx_struct(_this));
    if(result) {
        goto error;
    }

    cx_interface(_this)->kind = CX_DELEGATE;

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::lang::delegate::instanceof(object object) */
/* $header(::cortex::lang::delegate::instanceof) */
cx_bool cx_delegate_matchParameter(
    cx_type t1, 
    cx_bool isRef1, 
    cx_type t2, 
    cx_bool isRef2) {

    if ((t1 != t2) || (isRef1 && !isRef2)) {
        return FALSE;
    } else {
        return TRUE;
    }
}
/* $end */
cx_bool cx_delegate_instanceof(cx_delegate _this, cx_object object) {
/* $begin(::cortex::lang::delegate::instanceof) */
    cx_type t = cx_typeof(object);
    cx_bool result = TRUE;

    if ((t->kind == CX_COMPOSITE) && (cx_interface(t)->kind == CX_PROCEDURE)) {
        cx_function call = object;
        cx_uint32 i;

        /* Validate returntype */
        if (!cx_delegate_matchParameter(
            _this->returnType,
            _this->returnsReference,
            call->returnType,
            call->returnsReference)) {
            result = FALSE;
        }

        /* Validate number of parameters */
        if (_this->parameters.length != call->parameters.length) {
            result = FALSE;
        }

        /* Validate parameters */
        for (i = 0; i < _this->parameters.length; i++) {
            cx_parameter *p1, *p2;
            p1 = &_this->parameters.buffer[i];
            p2 = &call->parameters.buffer[i];
            
            if (!cx_delegate_matchParameter(
                p1->type,
                p1->passByReference,
                p2->type,
                p2->passByReference)) {
                result = FALSE;
            }
        }
    } else {
        result = FALSE;
    }

    return result;
/* $end */
}
