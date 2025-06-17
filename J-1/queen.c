#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int		is_safe(int *queen, int row, int col)
{
	int i = 0;
	while (i < row)// ??
	{
		if (queen[i] == col)
			return 1;
		if (abs(queen[i] - col) == abs(i - row))
			return 1;
		i++;
	}
	return 0;
}
void	board(int *queen, int n)
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
		printf("\n");
		row++;
	}
	printf("\n");
}

void	sol_queen(int *queen, int n, int row)
{
	if (n == row)
	{
		board(queen, n);
		return;
	}
	
	int col = 0;
	while (col < n)
	{
		if (is_safe(queen, row, col) == 0)
		{
			queen[row] = col;
			sol_queen(queen, n, row + 1);
		}
		col++;
	}
}

int main(int ac, char **av)
{
	int n = atoi(av[1]);
	int *queen = calloc(n, sizeof(int));
		if (!queen)	return 1;
	
	sol_queen(queen, n, 0);
	
}