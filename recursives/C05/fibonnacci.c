/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fibonnacci.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monoguei <monoguei@student.lausanne42.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:38:13 by monoguei          #+#    #+#             */
/*   Updated: 2025/05/19 12:00:53 by monoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_fibonacci(int index)
{
    if (index == 1) 
		return 1;
	else if (index  == 0)
		return 0;
    else
		return (fib(index - 1) + fib(index - 2));
	
    // fib(0) = 0
    // fib(1) = 1
    // fib(n) = fib(n-1) + fib(n-2)



}
squelette pour les listes chainee
f(list) 
{
  g(head) // tu fais un truc sur la tête
  if (tail) // si il reste quelque chose dans ta liste
    f(tail)// japplique f de facon recursive
}

list = head + tail
list = {1, 2 ,3 , 4}
head = 1
tail = {2, 3, 4}


https://www.geeksforgeeks.org/recursion-practice-problems-solutions/