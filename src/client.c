#include "base2d.h"
#include "memtracker.h"
#include "display.h"
#include <stdio.h>

int main(int argc, char **argv) {
	//Construct a new base2d object
	BASE2D *game = base2d_construct(VIDEO|AUDIO);

	//Detect if base2d initialize properly
	if (!(game->init(game))) {
		printf("Could not initialize base2d\n");
		base2d_destruct(game);
		return -1;
	}
	
	//Construct a new display
	DISPLAY *display = display_construct(640,480,"Display",VISIBLE);
	used();
	
	if (game->is_running(game)) {
		display->show(display);
		printf("BASE2D is running by extension of SDL, Testing Complete\n");
		pause(2000);
	} else {
		printf("Some error ocured!\n");	
	}

	//base2d must be destructed last
	display_destruct(display);
	base2d_destruct(game);
	used();
	return 0;
}
