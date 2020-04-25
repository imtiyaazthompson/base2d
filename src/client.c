#include "base2d.h"
#include <stdio.h>

int main(int argc, char **argv) {
	//Construct a new base2d object
	BASE2D *game = Base2D(VIDEO|AUDIO);
	game->init(game);
	if (game->is_running(game)) {
		printf("BASE2D is running by extension of SDL, Testing Complete\n");
		printf("Using flags: %d\n", game->get_flags(game));
	} else {
		printf("Some error ocured!\n");	
	}
	return 0;
}
