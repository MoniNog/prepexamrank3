/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moni_rip copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:45:04 by monoguei          #+#    #+#             */
/*   Updated: 2025/06/07 20:54:31 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		count_extra_parentheses(char *s)
{
	int count = 0;
	int i = 0;

	while(s[i])
	{
		if (s[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

char *remove_par(char *s)
{
	int i = 0;
	int start;
	int open;
	int close;
	int end;
	int extra;

	while (s[i] == ')')
		s[i++] = ' ';
	while (s[i])
	{
		open = 0;
		close = 0;
		start = i;				
		while (s[i] == '(')
		{
			open++;
			i++;
		}
		while (s[i] == ')')
		{
			i++;
			close++;
		}	
		end = i - 1;			
		extra = (open - close);	
		if (extra < 0)
		{
			i = end + extra;
			while (extra < 0)
			{
				s[i] = ' ';
				i++;
				extra++;
			}
		}
		if (extra > 0)
		{
			i = start;
			while (extra > 0)
			{
				s[i] = ' ';
				i++;
				extra--;
			}
		}
		i = end;
		i++;
	}
	return(s);
}

void print_spaces(int* pos, int size) {
	int i=0;
	while (i<size) {
		printf("%i ", pos[i]);
		i++;
	}
	printf("\n");
}

/// @brief 
/// @param n_space combien d'espace il reste a placer
/// @param size len de la str a imprimer
/// @param pos_spaces positions des espaces
/// @param total_spaces nombre total des espace a poser
void	place_space(int n_space, int size, int *pos_spaces, int total_spaces)
{
	int i;
	if (size == i)
	{
		print_spaces(pos_spaces, size);
		return ;
	}
	if (i != 0)
		i = size - (total_spaces - n_space - 1) + 1;
	else
		i = 0;
	while (i < size)
	{
		if (pos_spaces[i])			//placement espace, attribution a tel emplacement
			place_space(n_space - 1, size, pos_spaces, total_spaces);
		i++;
	}
}
// size = 8
// n_space = 3
// total_space = 3
// pos_spaces = [ ] [ ] [ ]



int main(int ac, char **av)
{
	char *s = av[1];
	printf("The input is  '%s'.\n", s);
	printf("The result is '%s'.\n", remove_par(s));
	printf("There are %i extra parenthesis.\n", count_extra_parentheses(s));
	printf("There are %i parenthesis.\n", (int)strlen(s) - count_extra_parentheses(s));	
	int* pos = malloc(sizeof(int)*count_extra_parentheses(s));
	place_space(count_extra_parentheses(s), strlen(s), pos, count_extra_parentheses(s));
}
// 1 2 3 => OK
// 2 1 3
// 3 1 2
// 1 3 2
// 2 3 1
// 3 2 1

/*
doublons
afficher espace, parentheses en utilisant les positions
*/

// 0-16 
// 5 espaces a placer => 5 etapes

// E1 -> 2 // 16 poss 
// E2 -> 4 // 15 poss
// E3 -> 6 // 14 poss
// E4 -> 7 // 13 poss
// E5 -> 9 // 12 poss

// une etape, placer une reine
// une etape, placer un espace
// 	toutes les possibilite qui decoulent de

// void    solve_queen(int row, int n, int *queens)// chaque reine a un nombre correspondant a sa place sur la ligne
// {
// 	if (row == n)
// 	{
// 		print_board(queens, n);
// 		return ;
// 	}
// 	int col = 0;								// a chaque fois que j'ai change de ligne, je recommence sur la premiere colonne.
// //	while (emplacements possibles < len_tot)
// 	while (col < n)								// je teste les differents emplacements possible pour Q (autant que n, car dimension du board)
// 	{
// 		if (is_safe(col, row, queens) == YES)	// si je peux,
// 		{
// 			queens[row] = col;					// je place
// 			solve_queen(row + 1, n, queens);	// j'explore une possibilite a partir de la reine que jai pu placer
// 		}
// 		col++;									// je passe a la colonne suivante, emplacement suivant
// 	}
// }

// E0 : 5 - 5 = 0 
// E1 : 5 - 4 = 1
// E2 : 5 - 3 = 2
// E3 : 
// E4 : 


// Q1 = 3
// Q2 = 1
// Q3 = 5
// Q4 = 2
// les reines reprensente les emplacements dans les rangs
// les espaces sont places a tel emplacement

// E5 
// E4 2
// E3 5



// . . . . . 0 00000
// . . . . 0 . 00000
// . . . 0 . . 00000


// . . . . Q
// . . Q 
// Q 
// .

// _ _ _ _ _
// 0 1 2 3 4
// * 
//   *
//     * 