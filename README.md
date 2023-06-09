
# Game of Life Simulation

This is a simple implementation of Conway's Game of Life simulation in C++.

## Prerequisites

To run this program, you need the following:

- C++ compiler (e.g., g++)
- Standard C++ library
- Ubuntu terminal

## Usage

1. Open the Ubuntu terminal.
2. Compile the program using the following command: g++ life.cpp -o life

3. Run the program using the following command: ./life.o


4. Follow the on-screen instructions:
- You will be prompted to begin the simulation by entering 'y' or 'n'.
- If you enter 'y', the simulation will start displaying the generations of cells.
- Each generation will be displayed on the terminal.
- The simulation will automatically progress to the next generation.


Note: The simulation runs until the next generation is the same as the current generation.

## Customization

You can customize the simulation by modifying the following variables in the code:

- `const int rows` and `const int cols`: These variables define the dimensions of the grid.
- The initial generation is randomized, you can modify the randomization logic in the `generate` function if desired.
- The delay between generations can be adjusted by changing the value in the `usleep` function call.



