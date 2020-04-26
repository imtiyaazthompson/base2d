#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>

/*
 * Display flags - can be ORd together
 */

enum DFLAGS {
		FULL=SDL_WINDOW_FULLSCREEN,
		DESKTOP=SDL_WINDOW_FULLSCREEN_DESKTOP,
		HIDDEN=SDL_WINDOW_HIDDEN,
		RESIZABLE=SDL_WINDOW_RESIZABLE,
		VISIBLE=SDL_WINDOW_SHOWN
	};

/*
 * Forward declaration of struct/class
 */

typedef struct display DISPLAY;

/*
 * Define the display class
 */

struct display {
	//Fields
	int width;
	int height;
	SDL_Window *window;
	SDL_Surface *container;

	//Methods
	int (*get_width)(DISPLAY *this);
	int (*get_height)(DISPLAY *this);
	SDL_Window* (*get_window)(DISPLAY *this);
	SDL_Surface* (*get_container)(DISPLAY *this);
	void (*show)(DISPLAY *this);
};

/*
 * Define Constructor for the display
 */

DISPLAY* display_construct(int width,int height,char *caption,int flags);

/*
 * Define Destructor for the display
 */

void display_destruct(DISPLAY *this);

/*
 * Define methods
 */

int getter_width(DISPLAY *this);
int getter_height(DISPLAY *this);
SDL_Window* getter_window(DISPLAY *this);
SDL_Surface* getter_container(DISPLAY *this);
void updater(DISPLAY *this);

#endif
