/*
 * cx_rbtree.h
 *
 *  Created on: Apr 6, 2012
 *      Author: sander
 */

#ifndef CX_RBTREE_H_
#define CX_RBTREE_H_

#include "cx_object.h"
#include "cx_collection.h"

#ifdef __cplusplus
extern "C" {
#endif

cx_rbtree cx_rbtreeNew(cx_type keyType);
cx_rbtree cx_rbtreeNew_w_func(cx_equalsAction compare);
void cx_rbtreeFree(cx_rbtree tree);

void* cx_rbtreeGet(cx_rbtree tree, void* key);
void* cx_rbtreeGetPtr(cx_rbtree tree, void* key);
void cx_rbtreeSet(cx_rbtree tree, const void* key, void* value);
void cx_rbtreeRemove(cx_rbtree tree, void* key);
cx_bool cx_rbtreeHasKey(cx_rbtree tree, const void* key, void** value);
void* cx_rbtreeMin(cx_rbtree tree, void** key_out);
void* cx_rbtreeMax(cx_rbtree tree, void** key_out);
void* cx_rbtreeNext(cx_rbtree tree, void* key, void** key_out);
void* cx_rbtreePrev(cx_rbtree tree, void* key, void** key_out);
cx_uint32 cx_rbtreeSize(cx_rbtree tree);
int cx_rbtreeWalk(cx_rbtree tree, cx_walkAction callback, void* userData);
int cx_rbtreeWalkPtr(cx_rbtree tree, cx_walkAction callback, void* userData);
cx_type cx_rbtreeKeyType(cx_rbtree tree);

#ifdef __cplusplus
}
#endif

#endif /* CX_RBTREE_H_ */
