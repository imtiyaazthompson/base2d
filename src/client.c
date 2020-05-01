#include <stdio.h>
#include <stdlib.h>
#include "base2d.h"
#include "globals.h"

int main(int argc,char **argv) {
	// Init Base2D game
	init_env(VIDEO|AUDIO);

	// Init Display display
	init_disp(640,480,"Display",RESIZABLE|VISIBLE,make_color(255,255,255,255));

	// Game Loop
	state_t status;
	while (TRUE) {
		update();
		status = listen();
		if (!status) {
			break;
		}
		/* User Event Handles */
	}

	printf("base2d Closed\n");
	return 0;
}
