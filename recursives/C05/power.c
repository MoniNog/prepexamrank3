/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:23:31 by monoguei          #+#    #+#             */
/*   Updated: 2025/05/19 11:36:38 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int recursif_power(int nb, int power)
{
	if (power == 0)
		return (1);
	
	return (recursif_power(nb, power - 1) * nb);

    // 3^5 = 3 * 3 * 3 * 3 * 3

    // p(3,5) = p(3,4) * 3
}
int ft_iterative_power(int nb, int power)
{
	int res = nb;
	if (power == 0)
		return (1);
	while (power > 1)
	{
		res = res * nb;
		power--;
	}
    // 3^5 = 3 * 3 * 3 * 3 * 3
	return (res);
}

int main(int ac, char **av)
{
	printf("la resultat pour %d, est... %d\n", atoi(av[1]), ft_iterative_power(atoi(av[1]),atoi(av[2])));
	return 0;
}