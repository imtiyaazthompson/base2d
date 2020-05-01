#include "base2d.h"
#include "globals.h"

/*******************
 *	BASE2D     *
 *******************/

/*
 * Initialize SDL subsytems and Base2D
 */

state_t init_env(flag_t subsystems) {
	if (SDL_Init(subsystems) != 0) {
		game.is_running = FALSE;
		SDL_Log("Unable to init SDL: %s",SDL_GetError());
		return FALSE;
	} else {
		game.is_running = TRUE;
		return TRUE;
	}
}

/*
 * Check if an instance of Base2D is running
 */

state_t is_running() {
	return game.is_running;
}

/*
 * Set a delay in ms
 */

void pause(int time_ms) {
	SDL_Delay(time_ms);
}

/*
 * Close SDL subsystems and Base2D instance
 */

state_t quit() {
	SDL_Quit();
	game.is_running = FALSE;
	return TRUE;
}



/*******************
 *     DISPLAY     *
 *******************/

/*
 * Init display by creating window and container surface
 */ 

state_t init_disp(int w,int h,char *cap,flag_t video,color_t *rgba) {
	display = malloc(sizeof(Display));
	display->width = w;
	display->height = h;
	display->color = malloc(sizeof(color_t)*4);
	memcpy(display->color,rgba,sizeof(color_t)*4);
	display->window = NULL;
	display->container = NULL;

	display->window = SDL_CreateWindow(
				cap,
				SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED,
				w,
				h,
				video
			  );

	if (display->window == NULL) {
		printf("Could not create window.\n");
		printf("SDL_Error: %s\n",SDL_GetError());
		return FALSE;
	}

	display->container = SDL_GetWindowSurface(display->window);
	SDL_FillRect(
		display->container,
		NULL,
		SDL_MapRGBA(
				display->container->format,
				rgba[0],
				rgba[1],
				rgba[2],
				rgba[3]
	        )
	);

	free(rgba);
	return TRUE;	
}


/*
 * Getters
 */

int get_width() {
	return display->width;
}

int get_height() {
	return display->height;
}

SDL_Window* get_window() {
	return display->window;
}

color_t* get_color() {
	return display->color;
}

color_t get_red() {
	return display->color[0];
}

color_t get_green() {
	return display->color[1];
}

color_t get_blue() {
	return display->color[2];
}

color_t get_alpha() {
	return display->color[3];
}

SDL_Surface* get_surface() {
	return display->container;
}

/*
 * Update the window display
 */

void update() {
	SDL_UpdateWindowSurface(display->window);
}

/*
 * Since window was resized
 * Resize the container
 * Free old surface, create new surface will fillRect
 */

void resize_window() {
	SDL_FreeSurface(display->container);
	display->container = SDL_GetWindowSurface(display->window);
	SDL_FillRect(
		display->container,
		NULL,
		SDL_MapRGBA(
			display->container->format,
			get_red(),
			get_green(),
			get_blue(),
			get_alpha()		
		)
	);
}

void destruct_main_display() {
	SDL_FreeSurface(display->container);
	SDL_DestroyWindow(display->window);
	free(display->color);
	free(display);
}

/*******************
 *     EVENTMAN    *
 *******************/

// Encapsulate event->type in evm.event
state_t listen() {
	while (SDL_PollEvent(&(evm.trigger)) != 0) {
		if (evm.trigger.type == SDL_WINDOWEVENT) {
			if (evm.trigger.window.event == SDL_WINDOWEVENT_RESIZED) {
				display->width = evm.trigger.window.data1;
				display->height = evm.trigger.window.data2;
				resize_window();
			}
		} else if (evm.trigger.type == SDL_QUIT) {
			destruct_main_display();
			// Destroy other screens if any
			quit();
			return FALSE;
		} else {
			evm.event = evm.trigger.type;
		}
	}
	return TRUE;
}

/*******************
 *      UTILS      *
 *******************/

color_t* make_color(int r,int g,int b,int a) {
	color_t *color = malloc(sizeof(color_t)*4);
	color[0] = r;
	color[1] = g;
	color[2] = b;
	color[3] = a;

	return color;
}
