/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 22:01:08 by monoguei          #+#    #+#             */
/*   Updated: 2025/04/01 13:52:44 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void  filter(char *s, char *x)
{
	int i = 0;
	int len_x = strlen(x);
	int a = 0;
	int len_s = strlen(s);// len s
	int start;/// repere debut de sequence


	while (i < len_s)
	{
		a = 0;
		start = i;
		while (a < len_x && i < len_s && x[a] == s[i])
		{
			i++;
			a++;
		}
		if (a == len_x)
		{
			int j = 0;
			while (j < len_x)
			{
				printf("*");
				j++;
			}
			if (i >= len_s)// pourquoi ?
				break ;
			continue; // évite l'affichage double
		}
		else// pourquoi ?
			i = start; // réinitialise i à start en cas d'échec
		printf("%c", s[i]);
		i++;
	}
}
// 
// void	filter(char	*s, char *x){
	// int		lenx = strlen(x);
	// int		lens = strlen(s);
	// int		start;
	// int a;
// 
	// for (int i = 0; i < lens; i++){
		// start = i;
		// a = 0;
		// for (; a < lenx && i <lens && x[a] == s[i]; a++, i++);
		// if (a == lenx){
			// for (int j = 0; j < lenx; j++)
				// printf("*");
			// if (i >= lens)
				// break ;
			// continue ;
		// }
		// else
			// i = start;
		// printf("%c", s[i]);
	// }
// }
//  
int   main(int ac, char **av)
{
	  if (ac == 2)
	  {
		char*buf = malloc(sizeof(char) * 10);
		
		    int bytes_read;
	 	 while ((bytes_read = read(0, buf, 9)) > 0)
		{
			buf[bytes_read] = '\0';//pour manipuler une str, on a besoin que celle-ci soit terminée par \0.
			filter(buf, av[1]);
		}
		free(buf);
	  }
	  return (0);
}

// [ ] description en pseudocode de filter 



// '\0' oublie de vider le buffer -> 
// memcpy(avec les char qui reste a la position de size, buffer size - size)
// memmove doit copy dans lautre sens
