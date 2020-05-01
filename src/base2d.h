#ifndef BASE2D_H
#define BASE2D_H

#include <SDL2/SDL.h>
#include <stdlib.h>

/*************************
 *  SYMBOLIC CONSTANTS	 *
 ************************/

enum subsytems {
	VIDEO=SDL_INIT_VIDEO,
        AUDIO=SDL_INIT_AUDIO,
        TIME=SDL_INIT_TIMER,
        JOYSTICK=SDL_INIT_JOYSTICK,
        CONTROLLER=SDL_INIT_GAMECONTROLLER,
        RUMBLE=SDL_INIT_HAPTIC,
        EVENT=SDL_INIT_EVENTS,
        ALL=SDL_INIT_EVERYTHING
};

enum dispflags {
	FULL=SDL_WINDOW_FULLSCREEN,
        DESKTOP=SDL_WINDOW_FULLSCREEN_DESKTOP,
       	HIDDEN=SDL_WINDOW_HIDDEN,
        RESIZABLE=SDL_WINDOW_RESIZABLE,
        VISIBLE=SDL_WINDOW_SHOWN
};

enum states {FALSE,TRUE};


/*********************
 *    EVM CONST'S    *
 *		     *
 * UPDATE THIS LIST  *
 *********************/
enum event_types {
	QUIT=SDL_QUIT,
	WINDOW=SDL_WINDOWEVENT
};

enum window_stated {
	MOVED=SDL_WINDOWEVENT_MOVED,
	RESIZED=SDL_WINDOWEVENT_RESIZED,
	FOCUS=SDL_WINDOWEVENT_ENTER,
	UNFOCUS=SDL_WINDOWEVENT_LEAVE
};
/* KEYBOARD KEY CONSTANTS HERE */
/* MOUSE CONSTANTS HERE */

/************************
 *   TYPE DEFINITIONS   *
 ************************/

typedef unsigned char state_t;
typedef unsigned int flag_t;
typedef unsigned char color_t;

typedef struct base2d Base2D;
typedef struct display Display;
typedef struct eventman Eventman;

/************************
 *      STRUCTURES      *
 ************************/

struct base2d {
	state_t is_running;
};

struct display {
	int width;
	int height;
	color_t *color;
	SDL_Window *window;
	SDL_Surface *container;
};

struct eventman {
	SDL_Event trigger;
	SDL_EventType event;
};

/*********************
 *  FUNCTION DEF'S   *
 *		     *
 *  STRUCTS WILL BE  *
 *      GLOBAL       *
 *********************/

/*********************
 *	BASE2D	     *
 *********************/

state_t init_env(flag_t subsystems);
state_t is_running(void);
state_t quit(void);
void pause(int time_ms);

/*********************
 *      DISPLAY      *
 *********************/

state_t init_disp(int width,int height,char *cap,flag_t flags,color_t *rgba);
int get_width(void);
int get_height(void);
color_t* get_color(void);
color_t get_red(void);
color_t get_green(void);
color_t get_blue(void);
color_t get_alpha(void);
SDL_Window* get_window(void);
SDL_Surface* get_container(void);
void resize_window(void);
void update(void);
void destruct_main_display(void);

/*********************
 *	EVENTMAN     *
 *********************/

state_t init_evm(void);
state_t listen(void);
state_t handle_resize(void);
state_t handle_quit(void);

/*********************
 *	 UTILS	     *
 *********************/

color_t* make_color(int r,int g,int b,int a);
#endif
