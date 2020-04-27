#ifndef VECTOR2D_H
#define VECTOR2D_H

/*
 * Define all physics construncts
 * As well as game physics
 */

typedef struct vector Vector2D;

struct vector {
	double x;
	double y;
};

/*
 * Vector sum: u + v
 */

Vector2D add(Vector2D *u, Vector2D *v);

/*
 * Negate vector -1*u = -u
 */

void negate(Vector2D *u);

/*
 * Scalar product
 */

void kproduct(Vector2D *u,double k);

/*
 * Dot product
 */

double dotproduct(Vector2D *u,Vector2D *v);

/*
 * Get the magnitude of a vector
 */

double get_mag(Vector2D *u);

/*
 * Get the direction of a vector, radians
 */

double get_dir(Vector2D *u);

/*
 * Predict the next position of an objects
 * Based on a small time difference
 * Known velocity
 * And known starting position
 */

double predict_pos(Vector2D *vel,Vector2D *pos,double dt);
#endif
