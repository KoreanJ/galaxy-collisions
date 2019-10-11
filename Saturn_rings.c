#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Constants */
const double RADIUS = 1;            // Radius of ring
const double MASS_SATURN = 1;       // Mass of saturn
const int NUMPOINTS = 10;           // Number of bodies in each ring (including center point)
const double M_BODY = 0.001;        // Mass of each body
const double eta = 0.2;
const double timestep = 0.1;
const double final_time = 15;
const double epsilon_squared = 0.01;
const double G = 1;
double GM = G * MASS_SATURN;

/* Variables */
double gamma_factor = 0.0;          // Factor that determines how stable the ring is
double v_initial = 0.0;

/* Declaration of functions used */
void initialize();

/* Distribute NUMPOINTS around a center of mass evenly */
int main(int argc, char *argv[])
{
    /* Compute initial velocity using kepler orbits */
    v_initial = pow(GM / RADIUS, 0.5);
    
    /* Points components */
    double x[NUMPOINTS];
    double y[NUMPOINTS];
    double z[NUMPOINTS];
    double vx[NUMPOINTS];
    double vy[NUMPOINTS];
    double vz[NUMPOINTS];

    /* Initialize points in phase space */
    initialize(x, y, z, vx, vy, vz);
    
}

void initialize(double x[], double y[], double z[], double vx[], double vy[], double vz[])
{
    // Set all values to 0
    for (int i = 0; i < NUMPOINTS; i++)
    {
        x[i] = 0.0;
        y[i] = 0.0;
        z[i] = 0.0;
        vx[i] = 0.0;
        vy[i] = 0.0;
        vz[i] = 0.0;
    }

    // Calculate angle needed between each body
    double angle = 0.0;
    double angle_increment = (M_PI * 2) / NUMPOINTS;

    // Position bodies evenly around ring
    for (int i = 0; i < NUMPOINTS; i++)
    {
        // Calculate initial position and velocity
        x[i] = RADIUS * cos(angle);
        y[i] = RADIUS * sin(angle);

        // Set initial velocities
        vx[i] = -v_initial * sin(angle);
        vy[i] = v_initial * cos(angle);
        angle += angle_increment;
    }
    

    // Print initial conditions and position of each body (including center of mass)
    printf("%d %f %f %f %f\n", NUMPOINTS + 1, eta, timestep, final_time, epsilon_squared);
    printf("%14.7f %14.7f %14.7f %14.7f %14.7f %14.7f %14.7f\n", MASS_SATURN, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    for (int i = 0; i < NUMPOINTS; i++)
    {
        printf("%14.7f %14.7f %14.7f %14.7f %14.7f %14.7f %14.7f\n", M_BODY, x[i], y[i], z[i], vx[i], vy[i], vz[i]);
    }
    

}