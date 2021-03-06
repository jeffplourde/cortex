/* profiling.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "profiling.h"

/* $header() */

#include "profiling__keyvalue.h"

extern cx_threadKey profiling_key;

/*
 * topProfile can be a profile, the per-thread scope, or the root-scope
 */
static cx_object profiling_profileRoot(void) {
    return root_o;
}

static profiling_TlsValue *profiling_value(void) {
    cx_threadKey key = profiling_key;
    profiling_TlsValue *value = cx_threadTlsGet(key);

    if (!value) {
        cx_thread tid;
        cx_id name;
        cx_ll ll;
        cx_object topProfile;
        
        tid = cx_threadSelf();
        sprintf(name, "t%lu", cx_threadSelf());
        ll = cx_llNew();
        topProfile = cx_declare(profiling_profileRoot(), name, cx_void_o);
        if (ll && topProfile) {
            value = cx_malloc(sizeof(profiling_TlsValue));
            value->ll = ll;
            value->topProfile = topProfile;
            cx_threadTlsSet(key, value);
        } else if (!ll) {
            cx_error("Could not create scope for Profile objects of thread %lu", tid);
            cx_free(topProfile);
        } else {
            cx_error("Could not create cx_ll object for profiling start times");
            cx_llFree(ll);
        }
    }
    return value;
}

static void profiling_openProfile(profiling_TlsValue *value, cx_string name) {
    profiling_Profile *next = cx_declare(value->topProfile, name, cx_type(profiling_Profile_o));
    value->topProfile = next;
}

static void profiling_closeProfile(profiling_TlsValue *value, cx_time t) {
    profiling_Profile *top = value->topProfile;
    if (cx_checkState(top, CX_DEFINED)) {
        top->seconds += t.tv_sec;
        top->nanoseconds += t.tv_nsec;
        top->callCount += 1;
    } else {
        top->seconds = t.tv_sec;
        top->nanoseconds = t.tv_nsec;
        top->callCount = 1;
        cx_define(top);
    }
    value->topProfile = cx_parentof(top);
}

/* $end */

/* ::cortex::profiling::start(string name) */
cx_void profiling_start(cx_string name) {
/* $begin(::cortex::profiling::start) */
    cx_time *startTimePtr = cx_malloc(sizeof(cx_time));
    profiling_TlsValue *value = profiling_value();
    cx_timeGet(startTimePtr);
    cx_llInsert(value->ll, startTimePtr);
    profiling_openProfile(value, name);
/* $end */
}

/* ::cortex::profiling::stop() */
cx_void profiling_stop(void) {
/* $begin(::cortex::profiling::stop) */
    cx_time *startTimePtr;
    cx_time stopTime;
    cx_time difference;
    profiling_TlsValue *value;
    value = profiling_value();
    cx_timeGet(&stopTime);
    startTimePtr = cx_llTakeFirst(value->ll);
    difference = cx_timeSub(stopTime, *startTimePtr);
    cx_dealloc(startTimePtr);
    profiling_closeProfile(value, difference);
/* $end */
}
