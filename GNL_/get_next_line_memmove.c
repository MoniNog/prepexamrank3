#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

# define BUFFER_SIZE 15

int 	my_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

//ret PTR sur c
char	*my_strchr(char *s, char c)
{
	int i = 0;
	
	if (!s)
	{
		perror("ERROR : pas de buf\n");
		return NULL;
	}

	while (s[i])
	{
		if (s[i] == c)
			return(&s[i]);// on retourn le PTR sur le 'c'
		else
			i++;
	}
	return (NULL);
}

// ret dup'\0' (deja)malloc
char	*strdup(const char *s)
{
	char	*dup;
	if (!s)
		return NULL;

	int		i =	0;
	while(s[i])
		i++;

	dup = malloc(sizeof(char) * i + 1);
	if (!dup)
		return NULL;

	i = 0;

	while(s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';

	return dup;
}

//s1 = old
//s2 = new
//ret = total
char *strjoin(char *s1, char *s2)
{
	char	*s3; 	
	int i = 0; 	int j = 0;

	if(!s1 && !s2)
		return NULL;

	if (!s1)
		return(strdup(s2));

	if (!s2)
		return(strdup(s1));

	s3 = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) +1));
	if (!s3)
		return NULL;

	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';

	free (s1);

	return (s3);
}

//return new_str
char	*substr(char *s, int start, int len)
{
	char	*new_str;
	int		i;

	if (!s || len <= 0)
		return NULL;
	if(start >= my_strlen(s))// si start > size, return emptyline
		return(strdup(""));

	new_str = malloc(sizeof(char) * len + 1);
	if (!new_str)
		return NULL;
	
	i = 0;
	while (i < len && s[start + i])
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = '\0';

	return (new_str);
}

void *my_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;

	if (d < s) // Copie normale (vers l'avant)
	{
		for (size_t i = 0; i < n; i++)
			d[i] = s[i];
	}
	else // Copie en arrière pour éviter les chevauchements
	{
		for (size_t i = n; i > 0; i--)
			d[i - 1] = s[i - 1];
	}
	return dest;
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;

	static char buf[BUFFER_SIZE + 1]; // Stocke les restes entre appels
	char	*line = NULL;
	ssize_t	bytes_read;
	char	*pos_nl = NULL;

	while ((bytes_read = read(fd, buf + my_strlen(buf), BUFFER_SIZE - my_strlen(buf))) > 0)
	{
		buf[bytes_read + my_strlen(buf)] = '\0'; // Assurer le null-terminate
		pos_nl = my_strchr(buf, '\n'); // Chercher '\n'

		if (pos_nl) // '\n' trouvé
		{
			int index_nl = pos_nl - buf;
			char *buf_begin = substr(buf, 0, index_nl + 1); // Extraire la ligne complète
			line = strjoin(line, buf_begin);
			free(buf_begin);

			// 🔥 DEBUG AVANT MEMMOVE
			// printf("Avant memmove: buf = [%s]\n", buf);

			// ⚡ Correction : Ajuster la copie
			int len_rest = my_strlen(buf) - index_nl - 1;
			my_memmove(buf, buf + index_nl + 1, len_rest);
			buf[len_rest] = '\0'; // ✅ Ajout du terminateur pour éviter les bugs

			// 🔥 DEBUG APRÈS MEMMOVE
			// printf("Après memmove: buf = [%s]\n", buf);
			// if (my_strlen(buf) < BUFFER_SIZE)
			// {
			// 	bytes_read = read(fd, buf + my_strlen(buf), BUFFER_SIZE - my_strlen(buf));
			// 	buf[bytes_read + my_strlen(buf)] = '\0';
			// }
			
			break; // On arrête la lecture, car on a une ligne complète
		}
		else
			line = strjoin(line, buf); // Ajoute tout le buffer si pas de '\n'
	}

	return line;
}


int main()
{
	int fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("fd\n");
		return 1;
	}
	char	*line = get_next_line(fd);
	printf("line : %s", line);
	line = get_next_line(fd);
	printf("line : %s", line);
	close(fd);
	return 0;
}