#ifndef BASE2D_H
#define BASE2D_H

#include <SDL2/SDL.h>
#include "memtracker.h"

/*
 * base2d engine's core - handles SDL_Init() and SDL_Quit().
 * Treated as the Game object
 *
 * Author: Imityaaz Thompson
 * Date: 25 April 2020
 */

/*
 * Symbolic constants that map to SDL FLAGS
 * Flags are ORd together to init the various subsystems
 */
enum FLAGS {
		VIDEO=SDL_INIT_VIDEO,
		AUDIO=SDL_INIT_AUDIO,
		TIMET=SDL_INIT_TIMER,
		JOYSTICK=SDL_INIT_JOYSTICK,
		CONTROLLER=SDL_INIT_GAMECONTROLLER,
		RUMBLE=SDL_INIT_HAPTIC,
		EVENT=SDL_INIT_EVENTS,
		ALL=SDL_INIT_EVERYTHING
	};

/*
 * Symbolic constants for booleans
 */

enum bool {FALSE,TRUE};

/*
 * Forward declaration of base2d struct/class
 */

typedef struct base2d BASE2D;

/*
 * Defining the BASE2D class
 */

struct base2d {
	//FIELDS
	char is_started;
	unsigned int flag;
	
	//METHODS
	int (*init)(BASE2D *this);
	unsigned int (*get_flags)(BASE2D *this);
	char (*is_running)(BASE2D *this);
};

/*
 * Defining BASE2D methods
 * Methods will be written in base2d.c 
 */

int initializer(BASE2D *this);
unsigned int getter_flags(BASE2D *this);
char run_checker(BASE2D *this);

/*
 * Define BASE2D constructor
 */

BASE2D* base2d_construct(unsigned int ORDflag);

/*
 * Define BASE2D destructor
 */

void base2d_destruct(BASE2D *this);

/*
 * Utility functions
 */

void pause(int time_ms);
#endif
