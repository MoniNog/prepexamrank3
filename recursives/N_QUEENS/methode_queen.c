#include <stdio.h>
#include <stdlib.h>

int is_safe(int *queen, int col, int row)
{
	int i = 0;
	while (i < row)
	{
		if (queen[i] == col)
			return 1;
		if (abs(queen[i] - col) == abs(i - row))
			return 1;
		i++;
	}
	return 0;
}

void	print_board(int *queen, int size)
{
	int row = 0;
	int col = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (queen[row] == col)
				printf("Q ");
			else
				printf(". ");
			col++;
		}
		printf("\n");
		row++;
	}
	printf("\n");
}

void	n_queen(int *queen, int size, int col, int row)
{
	if (size == row)
	{
		print_board(queen, size);
		return ;
	}
	col = 0;
	while (col < size)
	{
		if (is_safe(queen, col, row) == 0)
		{
			queen[row] = col;
			n_queen(queen, size, col, row + 1);
		}
		col++;
	}
}

int main(int ac, char **av)
{
	int size = atoi(av[1]);
	int *queen = malloc(sizeof(int) * size);
		if (!queen)	return 1;
	for (int i = 0; i < size; i++)
	    queen[i] = -1;

	int row = 0;
	int col = 0;

	n_queen(queen, size, col, row);
	return 0;
}