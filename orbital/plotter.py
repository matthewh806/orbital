import sys
import matplotlib.pyplot as plot
import random
import math

def plot_output(bodies, outFile = None):
	fig = plot.figure()
	colors = ['r', 'g', 'y', 'm', 'c']

	max_range = 0
	for current_body in bodies:
		max_range_cur = max(max(current_body["x"]), max(current_body["y"]))
		max_range = max(max_range_cur, max_range)
		plot.plot(current_body["x"], current_body["y"], color=random.choice(colors), label=current_body["name"])

	plot.axis([-max_range, max_range, -max_range, max_range])
	plot.legend()

	plot.show()

def read_bodies(files=[]):
	bodies = []

	for file in files:
		with open(file) as f:
			name = str(f.readline()).strip('\n')
			x = []
			y = []
			z = []

			for line in f:
				input = line.strip('\n').split(',')
				x.append(float(input[0]))
				y.append(float(input[1]))
				z.append(float(input[2]))

		bodies.append({"name": str(name), "x": x, "y": y, "z": z})

	return bodies

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("error: no file list")

    names = sys.argv[1:]
    bodies = read_bodies(names)
    plot_output(bodies)