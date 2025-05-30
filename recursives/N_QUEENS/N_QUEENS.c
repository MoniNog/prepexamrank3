/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   N_QUEENS.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:57:28 by monoguei          #+#    #+#             */
/*   Updated: 2025/05/29 11:33:21 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define NO 0
#define YES 1

int is_safe(int col, int row, int *queens)
{
	int i = 1;
	while (i < row)
	{
		if (queens[i] == col)//
			return NO;
		if (abs(queens[i] - col) == abs(i - row))
			return NO;
		i++;
	}
	return YES;
}


void print_board(int *queens, int n)
{
	int row = 1;
	int col = 1;
	
	while (row <= n)
	{
		col = 1;
		while (col <= n)
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

void	solve_queen(int row, int n, int *queens)
{
	if (row == n + 1)
	{
		print_board(queens, n);
		return ;
	}
	int col = 1;
	while (col <= n)
	{
		if (is_safe(row, col, queens) == YES)
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
		int i = 0;
		int *queens = malloc(sizeof(int) * n + 1);
		if (!queens)
			return 1;
		while (i <= n)
			queens[i++] = 0;
		solve_queen(1, n, queens);
		free (queens);
		return 1;
	}
	return 0;
}