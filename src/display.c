#include "display.h"
#include "memtracker.h"
#include "local.h"

/*
 * Construct display
 * TODO
 * width and height correspond to container w,h
 * when implementing resize functionality, remember to generate a new container
 * for the new resized window, then update the width and height of the display
 */

DISPLAY* display_construct(int width, int height,char *cap,int flags) {
	size_t size = sizeof(DISPLAY);
	DISPLAY *new_display = malloc(size);
	new_display->width = width;
	new_display->height = height;
	
	new_display->window = NULL;
	new_display->window = SDL_CreateWindow(
		cap,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		flags
	);

	if (new_display->window == NULL) {
		printf("Could not create window!\n");
		printf("SDL_Error: %s\n",SDL_GetError());
		return NULL; //Implement error handling
	}

	//Now Create the container surface all objects render to
	new_display->container = NULL;
	new_display->container = SDL_GetWindowSurface(new_display->window);
	SDL_FillRect(new_display->container,NULL,SDL_MapRGB(new_display->container->format,BLK[0],BLK[1],BLK[2]));

	//Set callbacks
	new_display->get_width = getter_width;
	new_display->get_height = getter_height;
	new_display->get_window = getter_window;
	new_display->get_container = getter_container;
	new_display->show = updater;

	pack(size);
	return new_display;
}

/*
 * Destruct display
 */

void display_destruct(DISPLAY *this) {
	size_t size = sizeof(*this);
		
	//Destroy container surface
	SDL_FreeSurface(this->container);

	//Destroy the window
	SDL_DestroyWindow(this->window);

	//Free up DISPLAY
	free(this);

	unpack(size);
}

/*
 * Methods
 */

int getter_width(DISPLAY *this) {
	return this->width;
}

int getter_height(DISPLAY *this) {
	return this->height;
}

SDL_Window* getter_window(DISPLAY *this) {
	return this->window;
}

SDL_Surface* getter_container(DISPLAY *this) {
	return this->container;
}

/*
 * Update any changes that occur to the container
 * E.G after rendering entities etc.
 */

void updater(DISPLAY *this) {
	SDL_UpdateWindowSurface(this->window);
}
