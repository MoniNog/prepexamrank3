#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

// char buffer [11];
int main()
{
	void	*buffer;

	buffer = malloc((sizeof(char)) * 11);

	free(buffer);
}