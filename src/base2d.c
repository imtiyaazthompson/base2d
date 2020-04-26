#include "base2d.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Constructor for a base2d object
 * Sets the initial fields
 * Allocates callback functions as methods
 *
 */

BASE2D* base2d_construct(unsigned int ORDflags) {
	// Start tracking heap size after base2d is started
	init_tracking();

	size_t size = sizeof(BASE2D);
	BASE2D *new_base2d = malloc(size);
	new_base2d->flag = ORDflags;
	new_base2d->is_started = 0;
	new_base2d->init = initializer;
	new_base2d->get_flags = getter_flags;
	new_base2d->is_running = run_checker;

	pack(size);
	return new_base2d;
}

/*
 * Destructor for a base2d object
 * Calls free to free up memory on the heap
 */

void base2d_destruct(BASE2D *this) {
	size_t size = sizeof(*this);
	free(this);
	unpack(size);

	// Close all SDL subsystems
	SDL_Quit();
	printf("base2d successfully terminated\n");
}

/*
 * Initialize SDL with the given flag field
 * Log an SDL error if an error occurs with initialization
 */

int initializer(BASE2D *this) {
	if (SDL_Init(this->flag) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		this->is_started = FALSE;
		return FALSE;
	} else {
		printf("SDL was initialized!\n");
		this->is_started = TRUE;
		return TRUE;
	}
}

/*
 * Get the ORd flags
 *
 */

unsigned int getter_flags(BASE2D *this) {
	return this->flag;
}

/*
 * Check if an instance of base2d is running
 * 
 */

char run_checker(BASE2D *this) {
	return this->is_started;
}

/*
 * Utility functions
 */

void pause(int time_ms) {
	SDL_Delay(time_ms);
}
