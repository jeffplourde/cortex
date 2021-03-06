/* Fast__load.c
 *
 * This file is generated. Only insert code in appropriate places.
 */

#include "Fast.h"

/* $header() */
#include "Fast.h"
#include "cx_util.h"
#include "cx_loader.h"
#include "cx_file.h"
#include "cx_mm.h"

cx_threadKey Fast_PARSER_KEY;

/* Run a cortex file */
int fast_cortexRun(cx_string file, void* udata) {
    cx_char* source;
    Fast_Parser p;
    CX_UNUSED(udata);

    source = cx_fileLoad(file);
    if (source) {
        /* Create parser */
        p = Fast_Parser__create(source, file);

        /* Parse script */
        Fast_Parser_parse(p);
        cx_free(p);
        cx_dealloc(source);
    } else {
        goto error;
    }

    return 0;
error:
    return -1;
}
/* $end */

/* This function is the entrypoint for the library and * loads definitions of the 'Fast' scope */
int cortexmain(int argc, char* argv[]) {
    CX_UNUSED(argc);
    CX_UNUSED(argv);
    
    int result = Fast_load();
    
    /* $begin(cortexmain) */
    if (cx_threadTlsKey(&Fast_PARSER_KEY, NULL)) {
        return -1;
    }

    /* Register cortex extension */
    cx_loaderRegister("cx", fast_cortexRun, NULL);
    /* $end */

    return result;
}

