/*
 * cx__interface.h
 *
 *  Created on: Aug 9, 2012
 *      Author: sander
 */

#ifndef CX__COMPOSITE_H_
#define CX__COMPOSITE_H_

#include "cx_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

cx_int16 cx__interface_bindMember(cx_interface _this, cx_member o);
cx_int16 cx__interface_insertMembers(cx_interface _this);
cx_uint16 cx__interface_calculateAlignment(cx_interface _this);
cx_uint32 cx__interface_calculateSize(cx_interface _this, cx_uint32 base);
cx_member cx_interface_resolveMember_v(cx_interface _this, cx_string name);

cx_bool cx_interface_checkProcedureCompatibility(cx_function o1, cx_function o2);

cx_function* cx_vtableLookup(cx_vtable* vtable, cx_string member, cx_int32* i_out, cx_int32* d_out);
cx_bool cx_vtableInsert(cx_vtable* vtable, cx_function method);

#ifdef __cplusplus
}
#endif

#endif /* CX__COMPOSITE_H_ */
