#include <stdio.h>
#include <stdlib.h>

int	is_safe(int *queen, int row, int col)
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

void print_board(int *queen, int n)
{
	int col = 0;
	int row = 0;

	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			if (queen[row] == col)
				printf("Q ");
			else
				printf(". ");
			col++;
		}
		row++;
		printf("\n");
	}
	printf("\n");
}

void	n_queen(int *queen, int n, int row)
{
	if (n == row)
	{
		print_board(queen, n);
		return;
	}
	int col = 0;
	while (col < n)
	{
		if (is_safe(queen, row, col) == 0)
		{
			queen[row] = col;
			n_queen(queen, n, row + 1);
		}
		col++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int n = atoi(av[1]);

		if (n == 1)
		{
			printf("Q\n");
			return 0;
		}

		if (n == 2 || n == 3)
		{
			printf("Aucun board possible avec ce nombre.\n");
			return 1;
		}

		int *queen = calloc(n, sizeof(int));
			if (!queen)		return 1;
		
		n_queen(queen, n, 0);
	}
}