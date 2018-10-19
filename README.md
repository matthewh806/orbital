# Orbital
![Orbital_Mess](https://github.com/matthewh806/orbital/blob/master/img/orbital_mess.png)

## Gravitational orbit simulations on your computer!

### Setup and running
While this project is still in development I haven't focused so much on packaging it up and making it all run nice and smoothly.

The project is made up of a C++ component (for running the actual simulation and saving the data to disk) and a simple python script for plotting the output using pyplot. A shell script is also included to automate all of the individual steps.

The C++ portion currently doesn't require any external libraries or dependencies, so compiling that is is as simple as:
```console
g++ -o ./build//orbital -Wc++11-extensions -std=c++11 src/*.cpp
```

Running a simulation is then as simple as: `./build/orbital [iterations] [timestep]` where both `[iterations]` and `[timestep]` are integers. This outputs the orbits of all of the bodies in .dat files 

The Python script uses matplotlib.pyplot for outputting the data on a graph. So get that via pip (or whatever). At some point I'll include a requirements file and setup a venv in the shell script.

The python script can be run with `python plotter.py *.dat`.

But nevermind all of those individual steps, I've included a `simulate.sh` script. This:
- Checks if the build directory exists and if not runs make (compiling, linking the C++ code)
- Runs the simulation for `[iterations]` `[timestep]`
- Calls the plotter.py and displays the output graphically
