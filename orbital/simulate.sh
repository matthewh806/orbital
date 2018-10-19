if [ ! -d "/build" ]
then
    echo "build dir. not found, calling Makefile"
    make
fi

echo 'running orbital'
./build/orbital $1 $2

if [ $? = 0 ]
then
    echo "Orbital run success"
    echo 'plot output'
    python plotter.py *.dat
else
    echo "Orbital run failure"
fi



