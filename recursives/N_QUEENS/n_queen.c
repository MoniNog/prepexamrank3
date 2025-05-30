#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

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

void    print_board(int *queens, int n)
{
	int col = 0;
	int row = 0;

	while (row < n)
	{
		col = 0;//
		while (col < n)
		{
			if (queens[row] == col)//
				printf("Q");
			else
				printf(".");
			col++;
		}
		printf("\n");
		row++;
	}
	printf("\n");
	return ;
}

void    solve_queen(int row, int n, int *queens)
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
			solve_queen(row + 1, n, queens);
		}
		col++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int n = atoi(av[1]);
		if (n <= 0)//
			return (0);//
		if (n == 1)
		{
			printf("Q\n");
			return (1);
		}
		if (n == 2 || n == 3)
		{
			printf("Sorry there is no possible board.\n");
			return (0);
		}
		int *queens = malloc(sizeof(int) * n + 1);
		if (!queens)
			return (0);
		solve_queen(0, n, queens);

		free(queens);//
		return (1);
	}
	return (0);
}