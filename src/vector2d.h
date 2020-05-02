#ifndef VECTOR2D_H
#define VECTOR2D_H

/*
 * Define all physics construncts
 * As well as game physics
 */

typedef struct vector Vector2D;
typedef struct body Body;

struct vector {
	double x;
	double y;
};

struct body {
	double mass;
	Vector2D acc;
	Vector2D vel;
	Vector2D dis;
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
 * Get theta using reduction form
 */

double* get_theta(double rads);

/*
 * Apply a force in a given direction to a Body
 */

void apply_force(double newtons,double force_app_dir,Body *blob);

/*
 * Integrate acceleration -> velocity vector
 */

double integrate_acc(Vector2D acc,double lower,double upper);

/*
 * Print vector components
 */

void printv(Vector2D vec);

#endif
