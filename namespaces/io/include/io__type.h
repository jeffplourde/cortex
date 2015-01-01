/* io__type.h
 *
 *  Generated on Dec  1 2014
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef io__type_H
#define io__type_H

#include "cortex.h"
#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define io_file(o) ((io_file)o)

/* Type definitions */

/* ::cortex::io::fileMode */
typedef enum io_fileMode {
    IO_Read = 0,
    IO_Write = 1,
    IO_Append = 2,
    IO_ReadWrite = 3,
    IO_ReadAppend = 4
} io_fileMode;

/*  ::cortex::io::file */
CX_CLASS(io_file);
CX_CLASS_DEF(io_file) {
    cx_string name;
    io_fileMode mode;
    cx_bool binary;
    cx_word handle;
};
CX_SEQUENCE(cx_octet_seq, cx_octet,);

#ifdef __cplusplus
}
#endif
#endif

