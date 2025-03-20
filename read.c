#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

# define BUFFER_SIZE 10//taille du buffer

int main()
{
	int		fd;//fichier a lire
	char	*buffer;//espace mem ou est stocke la str
	ssize_t	bytes_read;//bytes lus

	fd = open("text.txt", O_RDONLY); 
	if (fd == -1)
		return 1;
	
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);// + 1 pour fin str propre
	if (buffer == NULL)
		return 1;
	
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';//permet fin str propre
		printf("bytes read : %i\n", (int)bytes_read);
		printf("lu : %s", buffer);//printf a besoin de '\0' pour savoir ou sarreter
	}

	free(buffer);
	close(fd);

	return 0;
}