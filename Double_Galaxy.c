#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Constants */
const double MASS_CENTER = 1;       // Mass of center
const double M_BODY = 0.001;       // Mass of each body
const double eta = 0.005;
const double timestep = 0.05;
const double final_time = 25;
const double epsilon_squared = 0.000001;
const double G = 1;
const double X_OFFSET = 2;              // Initial x-coordinate of starting point
const int NUM_GALAXIES = 2;             // 2 galaxies in this simulation
const int POINTS_IN_GALAXY = 297;       // 297 particles
const int MAX_POINTS = 596;             // 594 points, 2 center points
const double v_offset = 0.2236068;
double GM = G * MASS_CENTER;
double TILT_A = 15;                   // Tilt of Galaxy A in degrees
double TILT_B = 60;                     // Tilt of Galaxy B in degrees


/* Variables */
int NUMPOINTS = 12;         // Number of particles in each ring
int NUMPOINTS_INC = 3;
int NUM_RINGS = 11;
double radius = 0.2;            // Radius of rings in galaxy
double radius_inc = 0.05;
int k = 0;

/* Declaration of functions used */
void initialize();

/* Distribute NUMPOINTS around a center of mass evenly */
int main(int argc, char *argv[])
{
    // Attributes for each body
    double x[MAX_POINTS];
    double y[MAX_POINTS];
    double z[MAX_POINTS];
    double vx[MAX_POINTS];
    double vy[MAX_POINTS];
    double vz[MAX_POINTS];

    // Initialize
    initialize(x, y, z, vx, vy, vz);
    
}

void initialize(double x[], double y[], double z[], double vx[], double vy[], double vz[])
{
    // Variables
    double angle = 0.0;
    double angle_increment = 0.0;
    double velocity = 0.0;

    // Set all values to 0
    for (int i = 0; i < MAX_POINTS; i++)
    {
        x[i] = 0.0;
        y[i] = 0.0;
        z[i] = 0.0;
        vx[i] = 0.0;
        vy[i] = 0.0;
        vz[i] = 0.0;
    }


    /* Generate Galaxy A at (4, 0)*/
    for (int outer = 0; outer < NUM_RINGS; outer++)
    {
        // Calculate angle inc and velocity mult. for each ring
        angle_increment = (M_PI * 2) / NUMPOINTS;
        velocity = pow(GM / radius, 0.5);

        // Initialize tilt value in radians
        TILT_A = (-TILT_A * M_PI) / 180.0;
        
        // Position bodies evenly around ring
        for (int inner = 0; inner < NUMPOINTS; inner++)
        {
            x[k] = (radius * cos(angle)) * cos(TILT_A) + X_OFFSET;
            y[k] = radius * sin(angle);
            z[k] = radius * cos(angle) * sin(TILT_A);
            vx[k] = -velocity * sin(angle) * cos(TILT_A);
            vy[k] = velocity * cos(angle) + v_offset;
            vz[k] = -velocity * sin(angle) * sin(TILT_A);
            angle += angle_increment;
            k++;
        }

        radius += radius_inc;
        NUMPOINTS += NUMPOINTS_INC;
        angle = 0.0;
    }

    /* Generate Galaxy B at (-4, 0)*/
    NUMPOINTS = 12;
    radius = 0.2;
    for (int outer = 0; outer < NUM_RINGS; outer++)
    {
        // Calculate angle inc and velocity mult. for each ring
        angle_increment = (M_PI * 2) / NUMPOINTS;
        velocity = pow(GM / radius, 0.5);
        
        // Initialize tilt value in radians
        TILT_B = (TILT_B * M_PI) / 180.0;

        // Position bodies evenly around ring
        for (int inner = 0; inner < NUMPOINTS; inner++)
        {
            x[k] = (radius * cos(angle)) * cos(TILT_B) - X_OFFSET;
            y[k] = radius * sin(angle);
            z[k] = radius * cos(angle) * sin(TILT_B);
            vx[k] = -velocity * sin(angle) * cos(TILT_B);
            vy[k] = velocity * cos(angle) - v_offset;
            vz[k] = -velocity * sin(angle) * sin(TILT_B);
            angle += angle_increment;
            k++;
        }

        radius += radius_inc;
        NUMPOINTS += NUMPOINTS_INC;
        angle = 0.0;
    }

    /* Print Header for File */
    printf("%d %f %f %f %f\n", MAX_POINTS, eta, timestep, final_time, epsilon_squared);

    /* Print Data for Galaxy A and B */
    printf("%14.7f %14.7f %14.7f %14.7f %14.7f %14.7f %14.7f\n", MASS_CENTER, X_OFFSET, 0.0, 0.0, 0.0, v_offset, 0.0);
    printf("%14.7f %14.7f %14.7f %14.7f %14.7f %14.7f %14.7f\n", MASS_CENTER, -X_OFFSET, 0.0, 0.0, 0.0, -v_offset, 0.0);
    for (int i = 0; i < MAX_POINTS - NUM_GALAXIES; i++)
    {
        printf("%14.7f %14.7f %14.7f %14.7f %14.7f %14.7f %14.7f\n", M_BODY, x[i], y[i], z[i], vx[i], vy[i], vz[i]);
    }
    

}