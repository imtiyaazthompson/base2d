#include "base2d.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Constructor for a base2d object
 * Sets the initial fields
 * Allocates callback functions as methods
 *
 */

BASE2D* Base2D(unsigned int ORDflags) {
	BASE2D *new_base2d = malloc(sizeof(BASE2D));
	new_base2d->flag = ORDflags;
	new_base2d->is_started = 0;
	new_base2d->init = initializer;
	new_base2d->get_flags = getter_flags;
	new_base2d->close = closer;
	new_base2d->is_running = run_checker;

	return new_base2d;
}

/*
 * Initialize SDL with the given flag field
 * Log an SDL error if an error occurs with initialization
 */

void initializer(BASE2D *this) {
	if (SDL_Init(this->flag) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		this->is_started = FALSE;
		this->close(this);
	} else {
		printf("SDL was initialized!\n");
		this->is_started = TRUE;
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
 * Close all SDL subsystems
 *
 */

void closer(BASE2D *this) {
	SDL_Quit();
}
