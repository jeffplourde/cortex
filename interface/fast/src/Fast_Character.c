/* Fast_Character.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Fast.h"
#include "Fast__meta.h"

/* $header() */
#include "Fast.h"
#include "Fast_Parser.h"
#include "Fast__api.h"
Fast_Parser yparser(void);
void Fast_Parser_error(Fast_Parser _this, char* fmt, ...);
/* $end */

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::Fast::Character::init(Character object) */
cx_int16 Fast_Character_init(Fast_Character object) {
/* $begin(::cortex::Fast::Character::init) */
    Fast_Literal(object)->kind = FAST_Character;
    return Fast_Literal_init(Fast_Literal(object));
/* $end */
}

/* ::cortex::Fast::Character::serialize(lang::type dstType,lang::word dst) */
cx_int16 Fast_Character_serialize(Fast_Character _this, cx_type dstType, cx_word dst) {
/* $begin(::cortex::Fast::Character::serialize) */
	Fast_valueKind kind;

	kind = Fast_valueKindFromType(dstType);

	switch(kind) {
	case FAST_Boolean:
		*(cx_bool*)dst = _this->value ? TRUE : FALSE;
		break;
	case FAST_Character:
	case FAST_Integer:
	case FAST_SignedInteger:
	case FAST_String:
		cx_convert(cx_primitive(cx_char_o), &_this->value, cx_primitive(dstType), (void*)dst);
		break;
	default: {
        cx_id id;
        Fast_Parser_error(yparser(), "cannot serialize character value to storage of type '%s'", cx_fullname(dstType, id));
        goto error;
		break;
	}
	}

	return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::Fast::Character::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_Character_toIc_v(Fast_Character _this, cx_icProgram program, cx_icStorage storage, cx_bool stored) {
/* $begin(::cortex::Fast::Character::toIc) */
	cx_ic result;
	cx_value v;
	CX_UNUSED(storage);
	CX_UNUSED(stored);

	cx_valueLiteralInit(&v, CX_LITERAL_CHARACTER, &_this->value);
	result = (cx_ic)cx_icLiteral__create(program, Fast_Node(_this)->line, v, cx_type(cx_char_o));

	return result;
/* $end */
}
