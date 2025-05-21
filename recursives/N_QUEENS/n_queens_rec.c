#include <stdio.h>
#include <stdlib.h>

int	*board;  // Stocke la ligne où est placée la reine pour chaque colonne
int	N;        // Taille de l'échiquier

// Vérifie si une reine peut être placée en (row, col)
int	is_safe(int row, int col)
{
	for (int i = 0; i < col; i++)
	{
		if (board[i] == row || abs(board[i] - row) == abs(i - col))
			return 0;  // en conflit
	}
	return 1;
}

// Récursion pour placer les reines
void	solve_nqueens(int col)
{
	if (col >= N)
	{
		// Affiche une solution
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				printf(board[j] == i ? "Q " : ". ");
			printf("\n");
		}
		printf("\n");
		return;
	}
	for (int row = 0; row < N; row++)
	{
		if (is_safe(row, col))
		{
			board[col] = row;
			solve_nqueens(col + 1);
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Usage: %s N\n", av[0]);
		return (1);
	}

	N = atoi(av[1]);
	if (N < 1 || N > 20)
	{
		printf("Erreur : N doit être entre 1 et 20.\n");
		return (1);
	}

	board = malloc(sizeof(int) * N);
	if (!board)
		return (1);

	solve_nqueens(0);

	free(board);
	return (0);
}
