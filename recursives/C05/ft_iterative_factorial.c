/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:00:53 by monoguei          #+#    #+#             */
/*   Updated: 2025/05/19 11:00:53 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_recursive_factorial(int nb)
{
	if (nb <= 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

int ft_iterative_factorial(int nb)
{
	int res;

	res = 1;
	while (nb > 0)
	{
		res = res * nb;
		nb--;
	}	
	return (res);
}

int main(int ac, char **av)
{
	printf("la resultat pour %d, est... %d\n", atoi(av[1]), ft_recursive_factorial(atoi(av[1])));
	return 0;
}
