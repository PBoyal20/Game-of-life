
#include <iostream>
#include <unistd.h>
#include <algorithm>

using namespace std;

const int rows = 10;
const int cols = 15;

int liveCount(int grid[rows][cols], int x, int y);
int generate();

int main()
{

	generate();

	return 0;
}
int generate()
{

	// Create Current Generation grid with randomized cells

	int currentGen[rows][cols];
	int nextGen[rows][cols];
	int liveCells;
	char ans;

	bool done = false;

	for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{

				currentGen[i][j] = rand() % 2;
			}
		}

	while (!done)
	{

		

		// Print current generation grid

		cout << "Current Generation" << endl;
		for (int i = 0; i < rows; i++)
		{
			cout << " ";
			for (int j = 0; j < cols; j++)
			{
				if (currentGen[i][j] == 0)
					cout << " . ";
				else
					cout << " * ";
			}

			cout << "" << endl;
		}

		// Create Next Generation of Cells

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{

				liveCells = liveCount(currentGen, i, j);

				if (currentGen[i][j] == 1 && (liveCells == 2 || liveCells == 3))
					nextGen[i][j] = 1;
				else if (currentGen[i][j] == 0 && liveCells == 3)

					nextGen[i][j] = 1;

				else
					nextGen[i][j] = 0;
			}
		}

		// Display Current Generation Grid

		cout << "\nNext Generation: " << endl;

		for (int i = 0; i < rows; i++)
		{
			cout << " ";
			for (int j = 0; j < cols; j++)
			{
				if (nextGen[i][j] == 0)
					cout << " . ";
				else
					cout << " * ";
			}
			cout << endl;
		}

		// set Next Gen to Current Gen

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				currentGen[i][j] = nextGen[i][j];
			}
		}

		cout << "End Simulation? (y/n)";
		cin >> ans;

		if (ans == 'y' || ans == 'Y')
			done = true;
		else
			done = false;
	}
	return 0;
}

int liveCount(int grid[rows][cols], int x, int y)
{
	int count = 0;

	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if ((i == x && j == y) || (i < 0 || j < 0) || (i >= rows || j >= cols))
			{
				continue;
			}
			if (grid[i][j] == 1)
			{
				count++;
			}
		}
	}
	return count;
}
