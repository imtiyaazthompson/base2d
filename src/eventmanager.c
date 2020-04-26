#include "eventmanager.h"
#include "memtracker.h"
#include "globals.h"

/*
 * Define Constructor for eventmanager
 */

EVENTMAN* eventmanager_construct() {
	size_t size = sizeof(EVENTMAN);

	EVENTMAN *em = malloc(size);
	em->listen = listener;
	pack(size);
	return em;
}

/*
 * Define Destructor for eventmanager
 */

void eventmanager_destruct(EVENTMAN *this) {
	size_t size = sizeof(*this);
	
	free(this);
	unpack(size);
}

/*
 * Define methods
 */


/*
 * Handle core events such as window resizing and auto filling container
 * surface.
 *
 * Handle quit event, destructs base2d,display and evm, then return
 * terminate status
 *
 * Otherwise, just return the event type that occured
 * Return no events if event queue is empty
 */
event_t listener() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_WINDOWEVENT) {
			if (e.window.event == SDL_WINDOWEVENT_RESIZED) {
				display->width = e.window.data1;
				display->height = e.window.data2;
				display->resize_container(display);
			}
		} else if (e.type == SDL_QUIT) {
			display_destruct(display);
			eventmanager_destruct(evm);
			base2d_destruct(game);
			return TERMINATE;
		} else {
			return e.type;
		}
	}
	return e.type;
}
