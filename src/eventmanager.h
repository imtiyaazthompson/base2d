#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <SDL2/SDL.h>

/*
 * Forward declaration of class/struct
 */

typedef struct eventmanager EVENTMAN;

/*
 * Define the event manager class
 */


/*
 * SDL has various events
 * Each event has fields: type
 * the Event->type can be used in a switch statement in each handler
 * base2d will handle events core to the engine
 * The end user will have to write their own functions to handle events 
 * such as movement events
 *
 * The listener will return an SDL_Event to the main game loop
 * All events will be handled inside the event controller
 */
struct eventmanager {
	// Methods

	//Listener that polls and returns an SDL_Event
	SDL_Event (*listen)(void);

	//Handlers - this is a growing list
	void (*handle_window)(SDL_Event event);
	int (*handle_quit)(SDL_Event event);
}

/*
 * Define methods
 */

void listener(void);
void window_handler(SDL_Event event);
int quit_handler(SDL_Event event);

/*
 * Define Constructor for event manager
 */

EVENTMAN* eventmanager_construct(void);

/*
 * Define Destructor for event manager
 */

void eventmanager_destruct(void);

#endif
