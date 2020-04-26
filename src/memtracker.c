#include "memtracker.h"
#include <stdio.h>

/*
 * Initialize HEAP memory tracking
 */

void init_tracking() {
	HEAP = 0;
}

/*
 * Display the current heap memory used by the entire program
 */

void used() {
	printf("Memory used: %ld bytes\n",HEAP);
}

/*
 * Increment the current HEAP size by size bytes
 */

void pack(size_t size) {
	HEAP += size;
}

/*
 * Decrement the current HEAP size by size bytes
 */

void unpack(size_t size) {
	HEAP -= size;
}
