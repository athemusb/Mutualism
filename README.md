# Code Description

The present code simulates the spatial pattern formation of a 1D obligatory-facultative Plant-Pollinator system. The virtual ecosystem contains N sites arranged in a 1D grid with periodic boundary conditions. The local dynamics are solved numerically via the Euler method, implemented in C. At the end, the population density time series and the final spatial state of the system are recorded.
Key Parameters
For executing the algorithm one must specify the grid size N, the number of time steps NG, and the integration step dt, present in the pp.h file.

# Compilation and Execution

You can execute the code simply running the `makefile`.

- Clean existing files from dat/ and plt/
```
make clean
```

- Compilation and Execution

./run.sh

# Data Processing

For this project, both the population density time series and final spatial states are of interest.
For generating the figures go to plt and:

- Density time series

```
gnuplot dst.plt && pdflatex #.tex
```

- Final State

```
gnuplot rps.plt
```

# Author
Matheus Bongestab
