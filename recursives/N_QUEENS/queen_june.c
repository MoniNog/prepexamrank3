#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define YES 1
#define NO 0

int	is_safe(int col, int *queens, int row)
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

void	print_bord(int *queens, int n)
{
	int col;

	int row = 0;
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			if (queens[row] == col)
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

void	solve_queens(int row, int n, int *queens)
{
	if (row == n)
	{
		print_bord(queens, n);
		return ;
	}
	int col = 0;
	while (col < n)
	{
		if (is_safe(col, queens, row) == YES)
		{
			queens[row] = col;
			solve_queens(row + 1, n, queens);
		}
		col++;
	}
}

int main(int ac, char **av)
{
	int n = atoi(av[1]);
	int *queens = malloc(sizeof(int) * n);
	if (!queens)	
		return NO;
	int i = 0;
	solve_queens(0, n, queens);
	return NO;
}

/*
Solve :
→ Où, combien, comment ? (row, n, queens)

Safe :
→ Puis-je poser ici ? (col, queens, row)

Print :
→ Quoi et combien ? (queens, n)
*/