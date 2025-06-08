#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// @brief Fonction récursive pour générer toutes les combinaisons valides de parenthèses en supprimant le minimum de parenthèses invalides.
/// @param len Longueur de la chaîne d'entrée.
/// @param s Chaîne temporaire pour stocker la solution courante.
/// @param input Chaîne d'entrée contenant les parenthèses.
/// @param i Indice courant dans la chaîne d'entrée.
/// @param open Nombre de parenthèses ouvrantes non fermées.
/// @param pos Position courante dans la chaîne temporaire.
/// @param to_remove_open Nombre de parenthèses ouvrantes à supprimer.
/// @param to_remove_close Nombre de parenthèses fermantes à supprimer.
void	rip(int len, char *output, char *input, int i, int open, int pos, int to_remove_open, int to_remove_close)
{
	if (i == len && open == 0 && to_remove_close == 0 && to_remove_open == 0)
	{
		output[len] = '\0';
		printf(">%s<\n", output);
		return ;
	}
	if (input[i] == '(')
	{
		output[pos] = '(';
		rip(len, output, input, i + 1, open + 1, pos + 1, to_remove_open, to_remove_close);
	
		if (to_remove_open > 0)
		{
			output[pos] = ' ';
			rip(len, output, input, i + 1, open, pos + 1, to_remove_open - 1, to_remove_close);
		}
	}
	if (input[i] == ')')
	{
		if (open > 0)
		{
			output[pos] = ')';
			rip(len, output, input, i + 1, open - 1, pos + 1, to_remove_open, to_remove_close);
		}
		if (to_remove_close > 0)
		{
			output[pos] = ' ';
			rip(len, output, input, i + 1, open, pos + 1, to_remove_open, to_remove_close - 1);
		}
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *input = av[1];
		int len = strlen(av[1]);
		char *output = malloc(sizeof(char) * len + 1);
			if (!output)	return 1;
		int to_remove_open = 0;
		int to_remove_close = 0;
		
		for (int i = 0; input[i]; i++)
		{
			if (input[i] == '(')
				to_remove_open++;
			else if (input[i] == ')')
			{
				if (to_remove_open > 0)
					to_remove_open--;
				else
					to_remove_close++;
			}
		}
		
		rip(len, output, input, 0, 0, 0, to_remove_open, to_remove_close);
	}
	return 0;
}