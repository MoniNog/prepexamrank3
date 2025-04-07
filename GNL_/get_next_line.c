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

/// @brief decoupe selon delimiteur
/// @param s string a decouper
/// @param start position de départ pour découper la chaîne
/// @param len longueur de la sous-chaîne à extraire
/// @return Retourne une nouvelle str correspondant à une sous-chaîne extraite de la chaîne d'entrée.
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
	static char 	*buf_static;
	ssize_t	bytes_read = 1;
	char	*line = NULL;
	char	*pos_nl = NULL;
	int		index_nl = 0;
	char	*buf_begin = NULL;

	if (!buf_static)
	{
		buf_static = malloc((sizeof(char)) * BUFFER_SIZE + 1);
		if (!buf_static)
			return NULL;
	} 
	else
		line = strdup(buf_static);
// tant quil y a qqch a lire (== EOF not found)
//		1. pos_nl	strchr
//		2. buf_beg 	(remplir pour commencer avec strdup(buf_static))
// si '\n' : 
//		1. identifier position de '\n'
//		2. decouper begin jusqua '\n'
//		3. attacher bagin a total
//		4. buf_static vient nous sauver pour save end_buf (ce quil reste apres '\n')
//		5. free(beg)
//		6. break
// else
//	   (3.)attacher bagin a total
	while (bytes_read > 0)//tant que EOF na pas ete trouve dans le buf
	{
		bytes_read = read(fd, buf_static, BUFFER_SIZE);
		pos_nl = my_strchr(buf_static, '\n');
		buf_begin = strdup(buf_static);

		if (pos_nl != NULL)// \n trouvee ! jattache debut du buf au total
		{
			index_nl = pos_nl - buf_static;// index en int (ecart entre les deux pointeurs)
			buf_begin = substr(buf_static, 0, index_nl);//je decoupe le debut jusqua '\n'
			line = strjoin(line, buf_begin);//jattache ce debut au total que jai deja
			buf_static = substr(buf_static, index_nl + 1, my_strlen(buf_static) - index_nl - 1);// le reste apres \n est stocke dans buf(buf maj)
			free(buf_begin);
			break ;
		}
		else
		{
			line = strjoin(line, buf_static);// si pas de \n, jattache la ligne (en entier) au total.
		}
// !!! [ ] voir quand EOF est identifier, pourquoi on naffiche pas la derniere ligne. quand je sors de mon while si EOF, print derniere ligne quand meme
	}
	if (bytes_read < 0)
	{
		printf("Error %i bytes_read\n", (int)bytes_read);
		return NULL;
	}
	//if EOF : print dernière ligne
	if (bytes_read == 0)
	{
		line = strjoin(line, buf_begin);
		line[bytes_read] = '\0';
		free(line);
	}

	return(line);
}

int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("fd\n");
		return 1;
	}
	
	char	*line;
	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		line = get_next_line(fd);
	}
	// printf("%s\n", line);

	close(fd);
	return 0;
}



// ___MONI ___ MONI ___ MONI___

// 	________prep EXAM_______

// 		[ ] ecrire prog sous forme de pseudocode
// 		[ ] schema avec les differentes fonctions nec/auxiliaires
// 		[ ] revoir fonctions permises durant lexamen

// 		[ ] finir philo
// 		[ ] avancer minishell dans les builtins 
