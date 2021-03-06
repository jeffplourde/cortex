/* tc_event__api.h
 *
 *  Generated on Feb  5 2014
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_event__API_H
#define tc_event__API_H

#include "tc_event__type.h"
#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::tc_event::Point */
tc_Point tc_Point__new(void);
tc_Point tc_Point__declare(cx_object _parent, cx_string _name);
int tc_Point__define(tc_Point _this, cx_uint32 x, cx_uint32 y);
tc_Point tc_Point__create(cx_uint32 x, cx_uint32 y);


#ifdef __cplusplus
}
#endif
#endif

