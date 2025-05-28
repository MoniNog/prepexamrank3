#include <stdin.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <c_lib.h>
#include <unistd.h>

define BUFFER_SIZE 3
define YES 0
define NO 1

char *get_next_line(int fd)
{
	static char *buf[BUFFER_SIZE + 1] = "";
	char *line;
	char *tmp;
	int bytes_read = BUFFER_SIZE;


	while (have_nl(tmp) == NO && bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE)
			if bytes_read = -1;
				return NULL;
		buf[bytes_read] = '\0';
		
		line = strjoin(line, buf);
	}
	if (have_nl(tmp))
	{
		begin = strdup(buf, taille jusqua nl)
		end = (buf, depuis nl, taille buf - nl + 1)
		line = strjoin(line, begin);
	}
	//lecture
	//decoupage
	//assemblage
	return (line);
}


no NL :
		read, join, boucle
  NL  :
		separe,
				avant NL join
				apres NL static buf 
			
	return line