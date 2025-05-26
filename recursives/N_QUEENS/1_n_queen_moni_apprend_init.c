/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_n_queen_moni_apprend_init.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:57:28 by monoguei          #+#    #+#             */
/*   Updated: 2025/05/26 11:50:06 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int	init_board(void)
{
	int row = 1;
	int i = 1;
	int *queen = malloc(sizeof(int) * 4);
	if (!queen)
		return 0;
	queen[1] = 1;
	queen[2] = 3;
	queen[3] = 2;
	queen[4] = 4;
	while (row < 5)
	{
		printf("the queen %i is at the col %i\n", row, queen[i]);
		i++;
		row++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		init_board();
	}
	return 0;
}