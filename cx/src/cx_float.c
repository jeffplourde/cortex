/* cx_float.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* ::cortex::lang::float::init() */
cx_int16 cx_float_init(cx_float _this) {
/* $begin(::cortex::lang::float::init) */
    cx_primitive(_this)->kind = CX_FLOAT;
    return cx_primitive_init((cx_primitive)_this);
/* $end */
}
