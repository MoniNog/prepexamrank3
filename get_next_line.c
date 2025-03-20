#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

# define BUFFER_SIZE 10
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

// ️// Vérifier si le fd est valide et initialiser le stockage.
// 	// fd = open("text.txt", O_RDONLY);

// ;
char	*get_next_line(int fd)
{

	char	*buf;

	buf = malloc((sizeof(char)) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return NULL;

	ssize_t	bytes_read;

	char	*line = NULL;
	char	*pos_nl = NULL;

	while((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)//tant que \n na pas ete trouve dans le buf
	{
		pos_nl = my_strchr(buf, '\n');
		char	*buf_begin = strdup(buf);
		int		index_nl;

		if (pos_nl != NULL)// \n trouvee ! jattache debut du buf au total
		{
			index_nl = pos_nl - buf;
			buf_begin = substr(buf, 0, index_nl);//je decoupe le debut
			line = strjoin(line, buf_begin);//jattache ce debut au total que jai deja
			buf = substr(buf, index_nl + 1, my_strlen(buf) - index_nl - 1);// le reste apres \n est stocke dans buf(buf maj)
			free(buf_begin);
		}
		else
			line = strjoin(line, buf);// si pas de \n, jattache la ligne (en entier) au total.
	}

	if (bytes_read <= 0)
	{	
		free(line);
		printf("Error %i bytes_read\n", (int)bytes_read);
		return NULL;
	}

	free(buf);
	return(line);
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
	close(fd);
	return 0;
	memcpy()
}