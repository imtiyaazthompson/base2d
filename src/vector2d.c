#include "vector2d.h"
#include "math.h"

/*
 * base2d is at its core a game engine for simulations
 * in 2D space
 * This requires the use of the equations of motion in
 * 2 dimensions.
 * So ideally this would be a good game engine for 2d plat-
 * formers and rigid body physics simulations in 2d
 *
 * base2d will also incorporate physics in one dimension
 */

Vector2D add(Vector2D *u,Vector2D *v) {
	Vector2D sum;
	sum.x = u->x + v->x;
	sum.y = u->y + v->y;
	return sum;
}

void negate(Vector2D *u) {
	u->x *= -1;
	u->y *= -1;	
}

void kproduct(Vector2D *u,double k) {
	u->x *= k;
	u->y *= k;
}

double Vector2D dotproduct(Vector2D *u,Vector2D *v) {
	double scalar;
	scalar = (u->x * v->x) + (u->y * v->y);	
	return scalar
}

double get_mag(Vector2D *u) {
	double mag;
	double x_comp = u->x * u_x;
	double y_comp = u->y * u_y;
	mag = sqrt(x_comp + y_comp);
}

double predict_pos(Vector2D *vel,Vector2D *pos,double dt) {

	
}

double get_dir(Vector2D *u) {
	double x_comp = u->x;
	double y_comp = u->y;
	double angle;
}
