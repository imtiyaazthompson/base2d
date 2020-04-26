#include "base2d.h"
#include "memtracker.h"
#include "display.h"
#include "eventmanager.h"
#include "globals.h"
#include "local.h"
#include <stdio.h>


int main(int argc, char **argv) {
	// Construct a new base2d object
	game = base2d_construct(VIDEO|AUDIO);

	// Detect if base2d initialized properly
	if (!(game->init(game))) {
		printf("Could not initialize base2d\n");
		base2d_destruct(game);
		return TERMINATE;
	}
	
	// Construct a new display
	display = display_construct(640,480,"Display",VISIBLE|RESIZABLE);

	// Construct a new eventmanager
	evm = eventmanager_construct();

	// Print current heap memory usage
	used();
	

	// Main Game Loop
	event_t event;
	while (TRUE) {
		// Update the display
		display->show(display);

		// Start listening for events
		event = evm->listen();
		if (event > 0) {
			printf("Event just occured: %d\n",event);
		} 
		
		if (event == -1) {
			break;
		}
	}

	used();
	return 0;
}
