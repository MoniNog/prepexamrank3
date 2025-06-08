#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define YES 1
#define NO 0

int     is_safe(int col, int row, int *queens)
{
	int i = 0;
	while (i < row)
	{
		if (queens[i] == col)
			return NO;
		if (abs(queens[i] - col) == abs(i - row))
			return NO;
		i++;
	}
	return YES;
}

void	print_board(int* queens, int n)
{
	int col;
	int row = 0;
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			if (queens[row] == col)
				printf(" Q");
			else
				printf(" .");
			col++;
		}
		printf("\n");
		row++;
	}
	printf("\n");
}

void	solve(int row, int *queens, int n)
{
	if (row == n)
	{
		print_board(queens, n);
		return ;
	}
	int col = 0;
	while (col < n)
	{
		if (is_safe(col, row, queens) == YES)
		{
			queens[row] = col;
			solve(row + 1, queens, n);
		}
		col++;
	}
}



int main(int ac, char **av)
{
	if (ac == 2)
	{
		int n = atoi(av[1]);
		int *queens = malloc(sizeof(int) * n);
		if (!queens)
			return 0;
		solve(0, queens, n);
		free (queens);
		return 1;
	}
	printf("\n");
	return 0;
}
