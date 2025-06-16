#include <stdio.h>
#include <stdlib.h>

int	is_safe(int *queens, int col, int row)
{
	int i = 0;
	while (i < row)
	{
		if (queens[i] == col)
			return 0;
		if (abs(queens[i] - col) == abs(i - row))
			return 0;
		i++;
	}
	return 1;
}

void	print_board(int *queens, int n)
{
	int col = 0;
	int row = 0;
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			if (queens[row] == col)
				printf("Q");
			else
				printf(".");
			col++;
		}
		row++;
		printf("\n");
	}
	printf("\n");
}


void	n_queen(int *queens, int n, int row, int col)
{
	if (row == n)
	{
		print_board(queens, n);
		return ;
	}
	col = 0;
	while (col < n)
	{
		if (is_safe(queens, col, row) == 1)
		{
			queens[row] = col;
			n_queen(queens, n, row + 1, col);
		}
		col++;
	}
}

int main(int ac, char **av)
{
	int n = atoi(av[1]);// nombre de queen a placer
	// int *queens = malloc(sizeof(int) * n);
	// 	if (!queens)	return 1;
	// for (int i =0; i < n; i++)
	// 	queens[i] = -1;
	int *queens = calloc(n, sizeof(int));
		if (!queens)	return 1;
	n_queen(queens, n, 0, 0);
	return 0;
}