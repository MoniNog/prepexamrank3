#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NO 0
#define YES 1

int     is_safe(int *queen, int col, int row)
{
	int i = 0;
	while (i < row)//
	{
		if (queen[i] == col)    
			return NO;
		if (abs(queen[i] - col) == abs(i - row))
			return NO;
		i++;
	}
	return YES;
}

void    print_board(int *queen, int n)
{
	int row = 0;
	int col = 0;

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

void    solve(int row, int *queen, int n)
{
	if (row == n)
	{
		print_board(queen, n);
		return ;
	}
	int col = 0;
	while (col < n)
	{
		if (is_safe(queen, col, row) == YES)
			queen[row] = col;
		solve(row + 1, queen, n);
		col++;
	}
	return ;
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int n = atoi(av[1]);
		if (n <= 0)
			return NO;
		if (n == 2 || n == 3)
		{
			printf("That's not possible ...\n");
			return NO;
		}
		else
		{
			int row = 0;
			int col = 0;
			int *queen = malloc(sizeof(int) * n + 1);
			if (!queen)
				return NO;

			solve(0, queen, n);

			free(queen);
			return YES;
		}
	}
	return NO;
}