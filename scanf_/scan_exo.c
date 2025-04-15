#include <stdio.h>
#include <stdin.h>
#include <ctype.h>
#include <stdarg.h>

int scan_char(int fd, va_list ap)
{
	FILE	*file = stdin;
	int		c = fgetc(file);

	if(feof(file) || ferror(file))
		return 0;
	
		char	*ch = va_arg(ap, char *);
		*ch = (char)c;

	return 1;	
}

int	scan_int(int fd, va_list ap)
{
	FILE	*file = stdin;
	int		c;
	int		sign = 1;
	int		*num = va_arg(ap, int *);
	*num = 0;

	while ((c = fgetc(file)) !=  EOF && isspace(c))
		;

	if (c == '-')
	{
		sign = -1;
		c = fgetc(file);
	}

	if (!isdigit(c))
	{
		if (c != EOF)
			ungetc(c, file);
		return 0;
	}

	while (c != EOF && isdigit(c))
	{
		*num = *num * 10 + (c - '0');
		c = fgetc(file);
	}

	if (c != EOF)
		ungetc(c, file);

	return 1;
}


void	skip_input_space(int fd)
{
	FILE *file = stdin;
	int c;

	while(c = fgetc(file) != EOF && isspace(c))
		;

	if (c != EOF)
		unget(c, file);
}


int skip_space(int fd)
{
	FILE *file = stdin;
	int c;

	while ((c = fgetc(file)) != EOF && isspace(c))
		;

	if (c != EOF)
		ungetc(c, file);
}

int	skip_input_space(int fd)
{
	FILE *file = stdin;
	int c;

	while ((c = fgetc(file)) != EOF && isspace(c))
		;
	
	if (c != EOF)
		ungetc(c, line);

}


int scan_str(int fd, va_list ap)
{
	FIle * file = stdin;
	int c;
	char *s = va_arg(ap, char *);

	c = fget(file);
	if (c == EOF)
		return 0;
	
	while (c != EOF && !isspace(c))
	{
		*s++ = (char)c;
		c = fgetc(file);// "i++"
	}

	if (c != EOF)
		ungetc(c, file);

		return 1;
}













int	str(int fd)
{
	FILE *file = stdin;
	int c;
	char *s = va_arg(ap, char *);

	c = fgetc(file);
	if (c == EOF)
		return 0;

	while (c != EOF && isspace(c))
	{
		*s++ = (char)c;
		c = fgetc(file);
	}
	*s = '\0';

	if (c != EOF)
		ungetc(c, file);

	return 1;
}









int str(int fd)
{
	FILE *file = stdin;
	int c;
	char *s = va_arg(ap, char *);

	c = fgetc(file);

	if (c == EOF)
		return 0;

	while (c != EOF && !isspace(c))
	{
		*s++ = (char)c;
		c = fgetc(file);
	}
	*s = '\0';

	if (c != EOF)
		ungetc(c, file);

	return 1;
}


int str(int fd, va_list ap)
{
	FILE *file = stdin;
	int c;
	char *s = va_arg(ap, char *);

	c = fget(file);

	if (c == EOF)
		return 0;

	while ((c != EOF && !isspace(c)))
	{
		*s++ = (char)c;
		c = fgetc(file);
	}
	*s = '\0';
	
	if (c != EOF)
		ungetc(c, file);

	return 1;
}


EOF == return 0;
ungetc == push;
c = fgetc(file);// == pull, i++
