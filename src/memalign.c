#include <stdio.h>
#include "common.h"

void *memalign(size_t alignment, size_t size) {
    size = align8(size);
    void *res;
    pthread_mutex_lock(&lock);
    //size =  size_align(size);
    res = allocateMemory(size);
    debug_print("malloc success! The allocateblock address is : %p\n", res);
    //assert();
    pthread_mutex_unlock(&lock);
    return res;
}