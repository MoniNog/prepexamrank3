#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

// fonctions permises : fgetc, ungetc, 
// ferror, feof, isspace, isdigit, stdin, 
// va_start, va_copy, va_arg, va_end

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

// Fonctions autorisées : fgetc, ungetc, feof, ferror, isspace, isdigit, stdin, va_start, va_arg, va_end

int scan_char(int fd, va_list ap)
{
	FILE *file = stdin;
	int c = fgetc(file);

	if (feof(file) || ferror(file))
		return 0; // échec

	char *ch = va_arg(ap, char *);
	*ch = (char)c;

	return 1; // succès
}

int scan_int(int fd, va_list ap)
{
	FILE *file = stdin;
	int c;
	int sign = 1;
	int *num = va_arg(ap, int *);
	*num = 0;

	// Skip leading whitespace
	while ((c = fgetc(file)) != EOF && isspace(c))
		;

	// Gestion du signe négatif
	if (c == '-')
	{
		sign = -1;
		c = fgetc(file);
	}

	if (!isdigit(c))
	{
		if (c != EOF)
			ungetc(c, file);
		return 0; // échec
	}

	while (c != EOF && isdigit(c))
	{
		*num = *num * 10 + (c - '0');
		c = fgetc(file);
	}
	*num *= sign;

	if (c != EOF)
		ungetc(c, file);
	return 1; // succès
}

int scan_string(int fd, va_list ap)
{
	FILE *file = stdin;
	int c;
	char *s = va_arg(ap, char *);

	c = fgetc(file);
	if (c == EOF)
		return 0; // échec

	while (c != EOF && !isspace(c))
	{
		*s++ = (char)c;
		c = fgetc(file);
	}
	*s = '\0';

	if (c != EOF)
		ungetc(c, file);

	return 1; // succès
}

void skip_input_space(int fd)
{
	FILE *file = stdin;
	int c = fgetc(file);

	while (c != EOF && isspace(c))
		c = fgetc(file);

	if (c != EOF)
		ungetc(c, file);
}

int received_input(const char *format, va_list ap)//** -> *, fd -> 0
{
	switch (*format)//
	{
		case 'c':
			return scan_char(0, ap);
		case 'd':
			skip_input_space(0);
			return scan_int(0, ap);
		case 's':
			skip_input_space(0);
			return scan_string(0, ap);
		default:
			return -1;
	}
}

int ft_scanf(const char *format, ...)
{
	int i = 0;
	int result = 0;
	va_list ap;
	va_start(ap, format);//

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (received_input(&(format[i]), ap) != 1)
				break;
			else
				result++;
		}
		i++;
	}
	va_end(ap);//
	return result;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_scanf_char()
{
	printf("Enter a character: ");
	char c;
	ft_scanf("%c", &c);
	printf("You entered: %c\n", c);
}

void test_scanf_int()
{
	printf("Enter an integer: ");
	int num;
	ft_scanf("%d", &num);
	printf("You entered: %d\n", num);
}

void test_scanf_string()
{
	printf("Enter a string: ");
	char str[100];
	ft_scanf("%s", str);
	printf("You entered: %s\n", str);
}

int main(void)
{
	printf("Testing ft_scanf with different inputs:\n");

	printf("\nTest 1: Character input\n");
	test_scanf_char();

	printf("\nTest 2: Integer input\n");
	test_scanf_int();

	printf("\nTest 3: String input\n");
	test_scanf_string();

	return 0;
}