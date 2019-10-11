import matplotlib.pyplot as plt
import numpy as np
import math
from mpl_toolkits.mplot3d import Axes3D

# Constants
PRODUCE_IMAGES = 1          # Produce images of particles moving
SIDE_VIEW = 0               # Whether the view should be from the side
IN_FILE = 'initials.txt'   # Name of file to read points from
IMAGES_FROM_FILE = 'galaxy_rough.txt'
NUMPOINTS = 596
RING_RAD = 5

if PRODUCE_IMAGES:

    # Make animation from the side
    if SIDE_VIEW:

        # SAVE IMAGES OF POINTS BEING MOVED
        f = open(IMAGES_FROM_FILE, 'r')
        data = [line.strip().split() for line in f.readlines()]
        f.close()
        # print(data[0])

        for i in range(0, len(data)):

            # Plot all points after 1 iteration of calculations
            if i % NUMPOINTS == 0:
                fig = plt.figure(figsize = (10, 10))
                ax = fig.add_subplot(111, projection = '3d')
                ax.set_xlim(-4, 4)
                ax.set_ylim(-4, 4)
                ax.set_zlim(-4, 4)
                ax.scatter([float(x[2]) for x in data[i - NUMPOINTS:i]], [float(y[3]) for y in data[i - NUMPOINTS:i]], [float(z[4]) for z in data[i - NUMPOINTS:i]], c = 'blue', s = 2)
                fig.set_facecolor('black')
                ax.set_facecolor('black')
                ax.grid(False)
                ax.w_xaxis.set_pane_color((0.0, 0.0, 0.0, 0.0))
                ax.w_yaxis.set_pane_color((0.0, 0.0, 0.0, 0.0))
                ax.w_zaxis.set_pane_color((0.0, 0.0, 0.0, 0.0))

                # Save one image of points
                plt.savefig("out/out%003d.png"%(i // NUMPOINTS),dpi=80)

    # Make animation from the top
    else:

        # SAVE IMAGES OF POINTS BEING MOVED
        f = open(IMAGES_FROM_FILE, 'r')
        data = [line.strip().split() for line in f.readlines()]
        f.close()
        # print(data[0])

        for i in range(0, len(data)):

            # Plot all points after 1 iteration of calculations
            if i % NUMPOINTS == 0:
                fig = plt.figure(figsize = (10, 10))
                ax = fig.add_subplot(111)
                ax.set_xlim(-4, 4)
                ax.set_ylim(-4, 4)
                # ax.set_facecolor((0, 0, 0))
                ax.grid(False)

                # index_slice = int((i / 2) + 1)

                # # Plot Galaxy A in RED
                # ax.scatter([float(x[2]) for x in data[i - NUMPOINTS:index_slice]], [float(y[3]) for y in data[i - NUMPOINTS:index_slice]], c = 'red')
                
                # # Plot Galaxy B in BLUE
                # ax.scatter([float(x[2]) for x in data[index_slice:i]], [float(y[3]) for y in data[index_slice:i]], c = 'blue')

                ax.scatter([float(x[2]) for x in data[i - NUMPOINTS:i]], [float(y[3]) for y in data[i - NUMPOINTS:i]], c = 'blue', s = 2)

                plt.title('Mice Galaxy Collision (Top View) | N = ' + str(NUMPOINTS) + ' | t = ' + data[i][0] + ' megayears')
                plt.xlabel('X Position')
                plt.ylabel('Y Position')

                # Save one image of points
                plt.savefig("out/out%003d.png"%(i // NUMPOINTS),dpi=80)


else:

    # PLOT DATA IN 3-D PLANE
    f = open(IN_FILE, 'r')
    data = [line.strip().split() for line in f.readlines()]
    f.close()
    fig = plt.figure()
    ax = fig.add_subplot(111, projection = '3d')
    ax.set_xlim(-5, 5)
    ax.set_ylim(-5, 5)
    ax.set_zlim(-3, 3)
    plt.title('Mice Galaxy')

    x = [float(x[1]) for x in data[1:]]
    y = [float(y[2]) for y in data[1:]]
    z = [float(z[3]) for z in data[1:]]

    ax.scatter(x, y, z)
    plt.show()
