/* cx_primitive.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_primitive_H
#define cx_primitive_H

#include "cortex.h"
#include "cx_type.h"
#include "cx__type.h"
#include "cx__api.h"
#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::cortex::lang::primitive::castable(type type) */
cx_bool cx_primitive_castable(cx_primitive _this, cx_type type);

/* ::cortex::lang::primitive::castable(type type) */
cx_bool cx_primitive_castable_v(cx_primitive _this, cx_type type);

/* virtual ::cortex::lang::primitive::compatible(type type) */
cx_bool cx_primitive_compatible(cx_primitive _this, cx_type type);

/* ::cortex::lang::primitive::compatible(type type) */
cx_bool cx_primitive_compatible_v(cx_primitive _this, cx_type type);

/* ::cortex::lang::primitive::construct() */
cx_int16 cx_primitive_construct(cx_primitive _this);

/* ::cortex::lang::primitive::init() */
cx_int16 cx_primitive_init(cx_primitive _this);

#ifdef __cplusplus
}
#endif
#endif

