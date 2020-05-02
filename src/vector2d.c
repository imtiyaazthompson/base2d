#include "vector2d.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>

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

/*
 * Force acts on an object
 * Force acting on an object applies acceleration F=ma
 * An acceleration applies velocity (integrate accelaration), where a(t) = xt;
 * And a velocity imbues displacement (integrate velocity), where v(t) = Integrate(a(t))dt + C1;
 * https://www.grc.nasa.gov/WWW/K-12/airplane/newton.html, where d(t) = Integrate(v(t))dt + C2;
 */

const double PI = 3.14;

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

double dotproduct(Vector2D *u,Vector2D *v) {
	double scalar;
	scalar = (u->x * v->x) + (u->y * v->y);	
	return scalar;
}

double get_mag(Vector2D *u) {
	double mag;
	double x_comp = u->x * u->x;
	double y_comp = u->y * u->y;
	mag = sqrt(x_comp + y_comp);
}

double* get_theta(double rads) {
	double *with_dir = malloc(sizeof(double)*3);
	if (rads <= PI/2 && rads >= 0) {
		printf("Q1\n");
		with_dir[0] = rads; //theta
		with_dir[1] = 1.0; //Right is +ve
		with_dir[2] = -1.0; // Up is -ve
		return with_dir;
	} else if (rads > PI/2 && rads <= PI) {
		printf("Q2\n");
		with_dir[0] = PI-rads;
		with_dir[1] = -1.0;
		with_dir[2] = -1.0;
		return with_dir;
	} else if (rads > PI && rads <= 3*PI/2) {
		printf("Q3\n");
		with_dir[0] = PI + rads;
		with_dir[1] = -1.0;
		with_dir[2] = 1.0;
		return with_dir;
	} else {
		printf("Q4\n");
		with_dir[0] = 2*PI - rads;
		with_dir[1] = 1.0;
		with_dir[2] = 1.0;
		return with_dir;
	}
}

void apply_force(double newtons,double force_app_dir,Body *blob) {
	/* Direction in which the force is applied */
	double *theta = get_theta(force_app_dir);
	printf("Theta: %.2f, Dir_x: %.2f, Dir_y: %.2f\n",theta[0],theta[1],theta[2]);
	double lhs_mass = 1.0/blob->mass;
	printf("1/m is %.2f\n",lhs_mass);

	/* X - components */
	double x_force = newtons*cos(theta[0])*theta[1];
	printf("Fx: %.2f\n",x_force);
	//get accelaration x
      	double x_a = 1/blob->mass * x_force;
	printf("Ax: %.2f\n",x_a);
	
	
	/* Y - components */
	double y_force = newtons*sin(theta[0])*theta[2];
	printf("Fy: %.2f\n",y_force);
	double y_a = 1/blob->mass * y_force;
	printf("Ay: %.2f\n",y_a);

	blob->acc.x = x_a;
	blob->acc.y = y_a;
	free(theta);
}

//TODO Write integrator
/*double integrate_acc(Vector2D acc,int lower,int upper) {
	return 0.0;
}*/

void printv(Vector2D vec) {
	printf("[ %.2f , %.2f  ]\n",vec.x,vec.y);
}

int main()
{
	printf("Testing Vectors\n");
	Body boy;
	boy.acc.x = 0.0;
	boy.acc.y = 0.0;
	boy.mass = 50.0;
	printf("Boy at rest: ");
	printv(boy.acc);
	apply_force(125,2.0,&boy);
	printf("Applied 125N force, now boy has acc: ");
	printv(boy.acc);
	return 0;
}
