/* ic_scope.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "ic.h"

/* ::cortex::ic::scope::add(node n) */
cx_void ic_scope_add(ic_scope _this, ic_node n) {
/* $begin(::cortex::ic::scope::add) */
    cx_llAppend(_this->program, n);
/* $end */
}

/* ::cortex::ic::scope::addStorage(storage s) */
cx_void ic_scope_addStorage(ic_scope _this, ic_storage s) {
/* $begin(::cortex::ic::scope::addStorage) */
    cx_llAppend(_this->storages, s);
    cx_set(&s->scope, _this);
/* $end */
}

/* ::cortex::ic::scope::construct() */
cx_int16 ic_scope_construct(ic_scope _this) {
/* $begin(::cortex::ic::scope::construct) */
    ic_node(_this)->kind = IC_SCOPE;
    return ic_node_construct(ic_node(_this));
/* $end */
}

/* ::cortex::ic::scope::lookupStorage(string name,bool recursive) */
ic_storage ic_scope_lookupStorage(ic_scope _this, cx_string name, cx_bool recursive) {
/* $begin(::cortex::ic::scope::lookupStorage) */
    cx_iter storageIter;
    ic_storage result = NULL;

    storageIter = cx_llIter(_this->storages);
    while(cx_iterHasNext(&storageIter)) {
        result = cx_iterNext(&storageIter);
        if (!strcmp(result->name, name)) {
            break;
        } else {
            result = NULL;
        }
    }

    if (!result && _this->parent && recursive && !_this->isFunction) {
        result = ic_scope_lookupStorage(_this->parent, name, TRUE);
    }

    return result;
/* $end */
}

/* ::cortex::ic::scope::str(string in) */
cx_string ic_scope_str(ic_scope _this, cx_string in) {
/* $begin(::cortex::ic::scope::str) */
    cx_iter programIter, storageIter;
    ic_storage storage;
    cx_uint32 storages = 0;
    ic_node ic;
    cx_string result = in;

    storageIter = cx_llIter(_this->storages);
    while(cx_iterHasNext(&storageIter)) {
        storage = cx_iterNext(&storageIter);
        if (storage->kind == IC_VARIABLE) {
            storages ++;
        }
    }

    if (storages) {
        result = strappend(result, "%%scopepush\n");
    }

    storageIter = cx_llIter(_this->storages);
    while(cx_iterHasNext(&storageIter)) {
        storage = cx_iterNext(&storageIter);
        if (storage->kind == IC_VARIABLE) {
            cx_id id;
            result = strappend(result, "%%var %s %s\n", storage->name, cx_fullname(storage->type, id));
        }
    }

    programIter = cx_llIter(_this->program);
    while(cx_iterHasNext(&programIter)) {
        ic = cx_iterNext(&programIter);
        result = ic_node_str(ic, result);
        result = strappend(result, "\n");
    }

    if (storages) {
        result = strappend(result, "%%scopepop\n");
    }

    return result;
/* $end */
}
