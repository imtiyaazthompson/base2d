#ifndef TRACKER_H
#define TRACKER_H

#include <stdlib.h>

size_t HEAP;

void init_tracking(void);
void used(void);
void pack(size_t size);
void unpack(size_t size);

#endif
