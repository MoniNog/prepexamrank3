#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	ft_strncmp(const char *first, const char *second, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (first[i] != second[i] || first[i] == '\0' || second[i] == '\0')
			return ((unsigned char)first[i] - (unsigned char)second[i]);
		i++;
	}
	return (0);
}

void	ft_scanf(const char *format, ...)
{
	va_list		ap;//argument pointer, utilise pour acceder aux args variables dune ft.
	char		buffer[5];
	int			i = 0;

	va_start	(ap, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_strncmp(format, "s", 1) == 0)
			{	
				char *dest = va_arg(ap, char*);
				int total_read = 0;
				while (1)
				{
					i = read(0, buffer, sizeof(buffer) - 1);
					if (i <= 0)
						break;
					buffer[i] = '\0';
					strncat(dest, buffer, 10 - total_read - 1);
					total_read += i;
					if (strchr(buffer, '\n') || total_read >= 10 - 1)
						break;
				}
				dest[10 - 1] = '\0'; // Ensure null termination
			}
			if (ft_strncmp(format, "c", 1) == 0)
			{	
				i = read(0, buffer, 2);
				buffer[i - 1] = '\0';
				strcpy(va_arg(ap, char*), buffer);
			}
			else if (ft_strncmp(format, "i", 1) == 0)
			{	
				i = read(0, buffer, 5);
				buffer[i - 1] = '\0';
				int temp = atoi(buffer);
				*va_arg(ap, int*) = temp;
			}   
		}
		format++;
	}
 	va_end(ap);
}

int main(void)
{
	char	name[50];
	int		age;
	char	favchar;

	printf("What is your name ?\n");
	ft_scanf("%s", name);
	printf("Ok, your name is %s.\n", name);

	printf("What is your favorite char ?\n");
	ft_scanf("%c", &favchar);
	printf("Ok, your favorite char is %c.\n", favchar);
	
	printf("What is your age ?\n");
	ft_scanf("%i", &age);
	printf("Ok, your age is %i.\n", age);
	return (0);
}

/*
Je me demande comment `while (*format)` fonctionne

`va_start(ap, format)` utilise la variable format
		void	va_start(va_list ap, type);
		la famille va_... 	est utile pour les fonctions necessitant un nombre indefini d'arguments
		va_list	ap; 		doit etre declarer (cest comme ca..)
		va_start() 			initialise ap pour l'utiliser apres

`const char	*format` est l'unique param de la fonction a etre initialise
*/



// void	ft_define_n(char s, va_list ap, int *count)
// {
// 	if (s == 'c')
// 		ft_putchar (va_arg(ap, int), count);
// 	else if (s == 'i' || s == 'd')
// 		ft_putnbr(va_arg(ap, int), count);
// 	else if (s == 's')
// 		ft_putstr(va_arg(ap, char *), count);
// 	else if (s == 'p')
// 		ft_putptr(va_arg(ap, void *), count);
// 	else if (s == 'u')
// 		ft_putnbr_u(va_arg(ap, unsigned int), count);
// 	else if (s == 'x')
// 		ft_putnbr_hex_xlo(va_arg(ap, unsigned int), count);
// 	else if (s == 'X')
// 		ft_putnbr_hex_xup(va_arg(ap, unsigned int), count);
// 	else if (s == '%')
// 		ft_putchar(('%'), count);
// 	else
// 	{
// 		ft_putchar(('%'), count);
// 		ft_putchar((s), count);
// 	}
// }

// int	ft_printf(const char *s, ...)
// {
// 	int			i;
// 	va_list		ap;
// 	int			count;

// 	count = 0;
// 	va_start (ap, s);
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == '%')
// 		{
// 			i++;
// 			ft_define_n(s[i], ap, &count);
// 		}
// 		else
// 			ft_putchar((s[i]), &count);
// 		i++;
// 	}
// 	va_end(ap);
// 	return (count);
// }