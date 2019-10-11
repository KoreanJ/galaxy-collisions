# Galaxy Collisions Project
# Developed in UCSD course, PHYS 141

The purpose of this project is to understand how galaxies collide, how the particles interact with each other, and how we can represent those complex and immense collisions in Python. The integrators were written in C and developed by another student (I do not know his name and thus take NO credit for any of the algorithms written in C). 

The code structure is broken down into a few components:

# Galaxy/Object Creation
This is done in C. My code generates a standard (and obviously unrealistic) galaxy and outputs the position of each point (along with their associated velocities in 3-D space) to a text file. Later versions of this project introduced a "tilt" to the galaxies, since that is how they are truly represented in space. 

# Data Processing
I used a python script to read in all of the data and process each value individually. This was crucial to the entire project as tainted data led to poor simulations and incorrect models. 

# Plotting
The plotting was all done using Matplotlib 3-D plots. Each point was plotted in 3-D space, a screenshot of the image was then saved, and finally the images were compiled into a movie file.

