/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moni_rip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:45:04 by monoguei          #+#    #+#             */
/*   Updated: 2025/05/30 08:21:00 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		count_extra_parentheses(char *s)
{
	int count = 0;
	int i = 0;

	while(s[i])
	{
		if (s[i] == '(')
			count++;
		if (s[i] == ')')
			count--;
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
		s[i++] = '.';
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
				s[i] = '_';
				i++;
				extra++;
	
			}
		}
		if (extra > 0)
		{
			i = start;
			while (extra > 0)
			{
				s[i] = '-';
				i++;
				extra--;
	
			}
		}
		i = end;
		i++;
	}
	return(s);
}

int main(int ac, char **av)
{
	char *s = av[1];
	printf("There is %i extra parenthesis.\n", count_extra_parentheses(s));
	printf("The result is '%s'.", remove_par(s));
}