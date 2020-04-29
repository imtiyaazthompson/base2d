#include <stdio.h>
#include <stdlib.h>
#include "base2d.h"
#include "globals.h"

int main(int argc, char **argv) {
	// Init Base2D game
	init_env(/*flags*/);
	
	// Init Display display
	init_disp(/*width,height,cap,flags,rgba[4]*/);

	// Game Loop
	while (TRUE) {
		update();
		SDL_EventType = listen();
		/* User Event Handles */
	}
}
