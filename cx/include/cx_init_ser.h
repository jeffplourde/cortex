/*
 * cx_init_ser.h
 *
 *  Created on: July 12, 2014
 *      Author: sander
 */

#ifndef CX_INIT_SER_H_
#define CX_INIT_SER_H_

#include "cx_serializer.h"

#ifdef __cplusplus
extern "C" {
#endif
    
struct cx_serializer_s cx_ser_init(cx_modifier access, cx_operatorKind accessKind, cx_serializerTraceKind trace);

#ifdef __cplusplus
}
#endif

#endif /* CX_INIT_SER_H_ */
