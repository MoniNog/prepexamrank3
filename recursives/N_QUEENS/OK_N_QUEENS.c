/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens_moni_apprend.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:57:28 by monoguei          #+#    #+#             */
/*   Updated: 2025/05/25 17:32:42 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ctype.h>
# include <stdlib.h>
# include <stdio.h>

#define NO 0
#define YES 1

int is_safe(int row, int col, int *queens)
{
	int i = 0;
	while (i < row)
	{
		if (queens[i] == col)						// même colonne ?
			return NO;
		if (abs(queens[i] - col) == abs(i - row))	// même diagonale ?
			return NO;
		i++;
	}
	return YES;
}

void	print_board(int *queens, int n)
{
	int row = 0;
	int col = 0;

	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			if (queens[row] == col)
				printf("Q ");
			else
				printf("· ");
			col++;
		}
		printf("\n");
		row++;
	}
	printf("\n");
}

void solve_nqueens(int row, int n, int *queens)// row = 2// int*queens contient les colonee des reines dans lordre des lignes
{
	if (row == n)//dernier rang atteint
	{
		print_board(queens, n);
		return ;
	}
	int col = 0;
	while (col < n)// tant que je n'ai pas essaye toutes les colonnes
	{
		if (is_safe(row, col, queens) == YES)
		{
			queens[row] = col;// je place la reine dans la ligne row et la colonne col
			solve_nqueens(row + 1, n, queens);// je passe a la ligne suivante
		}
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
			return 1;
		if (n == 2 || n == 3)
		{
			printf("Aucune solution possible pour n = %d\n", n);
			return 1;
		}

		int *queens = malloc(sizeof(int) * n);
		if (!queens)
			return (1);

		solve_nqueens(0, n, queens);
		
		free(queens);//
		return (0);
	}
	return (1);
}