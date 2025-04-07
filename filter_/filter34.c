#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


// // void	filter(char *s, char *x)
// // {
// // 	int i = 0;
// // 	int a = 0;
// // 	int start = 0;

// // 	while(s[i])
// // 	{
// // 		a = 0;
// // 		start = i;
// // 		// printf("\n\ts[i](%c)\n", s[i]);
// // 			while(x[a] && s[i] && x[a] == s[i])
// // 			{
// // 				i++;
// // 				a++;
// // 			}
// // 				if(a == (strlen(x)))// sequence finie success
// // 				{
// // 							int j = 0;
// // 							while (j < (strlen(x)))// print *
// // 							{
// // 					J			printf("*");
// // 								// printf("\ns[i](%c), i(%i), x[a](%c), a(%i)\n", s[i], i, x[a], a);
// // 								j++;
// // 							}
// // 					if (!s[i])
// // 						break;
// // 					continue ;
// // 				}
// // 			else
// // 				i = start;
// // 			printf("%c", s[i]);
// // 			i++;
// // 	}
// // }

// // int main(int ac, char **av)
// // {
// // 	if(ac == 2)
// // 	{
// // 		char	*buf = malloc(sizeof(char) * 10);
// // 		if(!buf)
// // 			return 0;

// // 		int		bytes_read;
// // 		while ((bytes_read = read(0, buf, 9)) > 0)
// // 		{
// // 			buf[bytes_read] = '\0';
// // 			filter(buf, av[1]);
// // 		}
// // 		free(buf);
// // 	}
// // 	return 0;
// // }





// // int main(int ac, char **av)
// // {
// // 	if (ac == 2)
// // 	{
// // 		int bytes_read;
// // 		char *buf = malloc(sizeof(char) * 10);
// // 		while ((bytes_read = read(0, buf, 9)) > 0)
// // 		{
// // 			buf[bytes_read] = '\0';
// // 			filter(buf, av[1]);
// // 		}
// // 		free(buf);
// // 	}
// // 	return 0;
// // }

// void filter(char *s, char *x)
// {
// 	int a = 0;
// 	int i = 0;
// 	int start = 0;
// 	int lenx = strlen(x);
// 	int lens = strlen(s);

// 	while (s[i])
// 	{
// 		start = i;
// 		a = 0;
// 		while (s[i] && x[a] && s[i] == x[a])
// 		{
// 			i++;
// 			a++;
// 		}
// 		if (a == lenx)
// 		{
// 			int j = 0;
// 			while (j < lenx)
// 			{
// 				printf("*");
// 				j++;
// 			}
// 			if (!s[i])
// 				break ;
// 			continue ;
// 		}
// 		i = start;
// 		printf("%c", s[i]);
// 		i++;
// 	}
// }

// int main (int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		int bytes_read;
// 		char *buf = malloc(sizeof(char)* 10);
// 		while((bytes_read = read(0, buf, 9)) > 0)
// 		{
// 			buf[bytes_read] = '\0';
// 			filter(buf, av[1]);
// 		}
// 		free(buf);
// 	}
// 	return (0);
// }




void filter(char *s, char *x)
{
	int i = 0;
	int a = 0;
	int lenx = strlen(x);
	int lens = strlen(s);
	int start = 0;

	while (i < lens)
	{
		start = i;
		a = 0;
		while(s[i] && x[a] && s[i] == x[a])
		{
			i++;
			a++;
		}
		if (a == lenx)
		{
			int j = 0;
			while(j < lenx)
			{
				printf("*");
				j++;
			}
			if (!s[i])
				break ;
			continue ;
		}
		i = start;
		printf("%c", s[i]);
		i++;
		}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *buf = malloc(sizeof(char) * 10);
		int bytes_read;

		while ((bytes_read = read(0, buf, 9)) > 0)
		{
			buf[bytes_read] = '\0';
			filter(buf, av[1]);
		}
		free(buf);
	}
	return 0;
}

