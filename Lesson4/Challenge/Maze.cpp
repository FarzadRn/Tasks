#include <iostream>
#include <fstream>
#include <vector>
#define ROW 11
#define COLUMN 16
#define X 'X'//char(176)
#define Y 'Y'//char(178)
#define Z 'Z'//char(219)
#define W 'W'//char(177)
//X = a block that touches 2 or less space in a 90 degree angle. 4 possible corner. != touching Z
//Z = a block that touches S||E and <=2 spaces
//Y = if != touching Z and only 1 space
//W = only touching 2 spaces and !=z and also touching X or Y
// 
//program finds Z then X then Y then W then Y then Z for complete answer

void findZ(char grid[ROW][COLUMN], int uselessIterationCounter)
{
	bool wasEffectiveCycle = false;
	// char(32) = ' '
	char space = char(32);
	bool S_and_E_done = false;
	do {
		wasEffectiveCycle = false;
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COLUMN; j++)
			{
				//if (current != space, continue) AND (if out of bounds, continue)
				if ((grid[i][j] == space) && ((i - 1 >= 0) && (j + 1 < COLUMN) && (i + 1 < ROW) && (j - 1 >= 0)))
				{
					char up = grid[i - 1][j];
					char down = grid[i + 1][j];
					char left = grid[i][j - 1];
					char right = grid[i][j + 1];
					
					if ((up == Z || down == Z || left == Z || right == Z))
					{
						if (((up == space) + (left == space) + (down == space) + (right == space)) <= 1)
						{
							grid[i][j] = Z;
							wasEffectiveCycle = true;
						}
					}
					//resolve S E
					else if (!S_and_E_done)
					{
						if ((up == 'S' || down == 'S' || left == 'S' || right == 'S')/**/ || /**/((up == 'E' || down == 'E' || left == 'E' || right == 'E')))
						{
							grid[i][j] = Z;
							wasEffectiveCycle = true;
						}
					}
				}
			}
		}
		S_and_E_done = true;
	} while (wasEffectiveCycle);
}



void findX(char grid[ROW][COLUMN], int uselessIterationCounter)
{
	if (uselessIterationCounter >= 5)
	{
		return;
	}
	char space = char(32);
	char wall = '*';

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			if (grid[i][j] == char(32) && ((i - 1 >= 0) && (j + 1 < COLUMN) && (i + 1 < ROW) && (j - 1 >= 0)))
			{
				char up = grid[i - 1][j];
				char down = grid[i + 1][j];
				char left = grid[i][j - 1];
				char right = grid[i][j + 1];

				if ((up == wall && right == wall) && ((left == space || left == X) && (down == space || down == X)))
				{
					grid[i][j] = X;
				}
				else if ((up == wall && left == wall) && ((right == space || right == X) && (down == space || down == X)))
				{
					grid[i][j] = X;
				}
				else if ((down == wall && left == wall) && ((up == space || up == X) && (right == space || right == X)))
				{
					grid[i][j] = X;
				}
				else if ((down == wall && right == wall) && ((up == space || up == X) && (left == space || left == X)))
				{
					grid[i][j] = X;
				}
				else
				{
					uselessIterationCounter++;
				}
			}
		}
	}

	findX(grid, uselessIterationCounter);
}

void findY(char grid[ROW][COLUMN], int uselessIterationCounter)
{
	if (uselessIterationCounter >= 1)
	{
		return;
	}
	char space = char(32);

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			if (grid[i][j] == char(32) && ((i - 1 >= 0) && (j + 1 < COLUMN) && (i + 1 < ROW) && (j - 1 >= 0)))
			{
				char up = grid[i - 1][j];
				char down = grid[i + 1][j];
				char left = grid[i][j - 1];
				char right = grid[i][j + 1];

				//if no Z  and only 1 space
				if (!(up == Z || down == Z || left == Z || right == Z))
				{
					if ((up == space) + (left == space) + (down == space) + (right == space) == 1)
					{
						grid[i][j] = Y;
					}
					else
					{
						uselessIterationCounter++;
					}
				}
			}
		}
	}
	findY(grid, uselessIterationCounter);
}
void findW(char grid[ROW][COLUMN], int uselessIterationCounter)
{
	if (uselessIterationCounter >= 5)
	{
		return;
	}
	char space = char(32);

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			if (grid[i][j] == char(32) && ((i - 1 >= 0) && (j + 1 < COLUMN) && (i + 1 < ROW) && (j - 1 >= 0)))
			{
				char up = grid[i - 1][j];
				char down = grid[i + 1][j];
				char left = grid[i][j - 1];
				char right = grid[i][j + 1];

				if (!(up == Z || down == Z || left == Z || right == Z))
				{
					if (((up == X || up == Y || up == W) || (down == X || down == Y || down == W) || (left == X || left == Y || left == W) || (right == X || right == Y || right == W)))
					{
						if ((((up == space) + (left == space) + (down == space) + (right == space)) == 2))
						{
							grid[i][j] = W;
						}
						else
						{
							uselessIterationCounter++;
						}
					}
				}
				else if (up == Z || down == Z || left == Z || right == Z)
				{
					if (((up == space) + (left == space) + (down == space) + (right == space)) == 2)
					{
						grid[i][j] = Z;
					}

				}
			}
		}
	}
}

void cleanUpMaze(char grid[ROW][COLUMN])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			if ((grid[i][j] == X) || (grid[i][j] == Y) || (grid[i][j] == W))
			{
				grid[i][j] = char(32);
			}
		}
	}
}

int main()
{
	//maze renderer with nested loops & 2D arrays
	//1. load into 2D array 2.print out from array
	//function to find a path from S to E
	//display with solution

	// char(32) white space
	// char(219) white block
	// char(177) less white block
	// char(83) S
	// char(69) E

	std::ifstream InMaze("Maze.txt");
	char grid[ROW][COLUMN];

	if (InMaze.is_open())
	{
		int rowCounter = 0;
		char buffer[20];
		while (InMaze.getline(buffer, 19))
		{
			for (int i = 0; i < COLUMN; i++)
			{
				grid[rowCounter][i] = buffer[i];
			}
			rowCounter++;
		}
		InMaze.close();
	}
	findZ(grid, 0);
	findX(grid, 0);
	findY(grid, 0);
	findZ(grid, 0);
	findW(grid, 0);
	findY(grid, 0);
	findZ(grid, 0);
	//cleanUpMaze(grid);

	for (int rowCount = 0; rowCount < ROW; rowCount++)
	{
		for (int columnCount = 0; columnCount < COLUMN; columnCount++)
		{
			std::cout << grid[rowCount][columnCount];
		}
		std::cout << std::endl;
	}

}