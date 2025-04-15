#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 5

// /// @brief  The  memcpy() function copies n bytes from memory area src to
// /// memory area dest.  The memory areas must  not  overlap.   Use
// /// memmove(3) if the memory areas do overlap.
// void *ft_memcpy(void* dest, const void* src, size_t n) 
// {
//     while(--n > 0) 
// 	{
// 		(char*)dest[n-1] = (char*)src[n-1];
//     }
//     return dest;
// }

// void ft_memmove() {
    
// }

// void str_cpy() {
	
// }

// void strchr() {
	
// }

int str_append_mem(char **s1, char *s2, size_t size_2) 
{
	if (!s1)
		return 0;
	size_t	size_1 = strlen(*s1);// s1 = double ptr
	char	*tmp = malloc(size_2 + size_1 + 1);
	
	if (!tmp)
		return 0;// 0 error
	memcpy(tmp, *s1, size_1);	
	memcpy(tmp + size_1, s2, size_2);
	tmp[size_1 + size_2] = 0;
	free(*s1);
	
	*s1 = tmp;
	return 1;// 1 success
}	

int str_append_str(char** s1, char* s2) {
	if (str_append_mem(s1, s2, strlen(s2)))
		return 1;
	return 0;
}	


char * get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1] =  "";
	char *ret = NULL;
    char *tmp = NULL;
    int read_ret;
	tmp = strchr(b, '\n');
	// sil reste qqch dans b (appel de gnl avant). je dois accoler ce reste a ma new lign a lire
	while (!tmp)// tant que cest NULL ! il ny a pas de \n
	{
		//str_append_str est appele, append ret a b;
		if (!str_append_str(&ret, b))// si str_append_str echou, je quitte
			return NULL;
		read_ret = read(fd, b, BUFFER_SIZE);// read + stock nb bytes read dans read_ret REMPLISSAGE DU BUF
		if (read_ret == -1)
			return NULL;// si lecture echou, quitte
		tmp = strchr(b, '\n');
		b[read_ret] = 0;// "bxosabudooie[0]" pour fermer proprement la str
	}
	// cas ou '\n' trouvee : colle jusqua \n à ret et stock depuis \n dans b
	if (!str_append_mem(&ret, b, tmp - b + 1))// ret + b = ???[ ] (tmp - b + 1 = a size de b ?)[ ] b contiendra plus que la 2eme partie
	{
		free(ret);
		return NULL;
	}
	// printf("tmp : %s\n",tmp);
	// printf("tmp : %d\n", *tmp);
	memmove(b, tmp + 1, strlen(tmp + 1) + 1);
	return (ret);// contenu de la line;
}

int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	
	return 0;
}

/*
	1. commencer par les fonctions nouvelles
	utiliser les ft de la lib temporairement et me concentrer ce qui est nouveau
	2. lire la ***fonction main*** et comprendre ce qui est fait, 
			ce que voulait faire le codeur, 
			comment il utilise les foncitons auxiliaires
	3. chercher les bizarerie, sorcelerie, chimie explosive
	4. faire fonctionner le code
	5. noter les verif qui me viennent en tete
	6. ecrire un main
	6. checker les fonctions auxiliaires ***individuellement***
	...
	10. penser aux cas limites
*/