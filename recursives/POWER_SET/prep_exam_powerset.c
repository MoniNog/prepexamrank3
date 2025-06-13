#include <stdio.h>
#include <stdlib.h>

void	powerset(int *set, int nb_set, int *subset, int len, int sum, int target, int pos)
{
	if (sum == target)
	{
		for (int i = 0; i < len; i++)
			printf("%i ", subset[i]);
		printf("\n");
		return;
	}
	int i = pos;			//initilisation => dépend de l'étape précédente
	while (i < nb_set)		//condition de fin => exploration de tous les choix possibles à cette étape
	{
		if (sum <= target)	//est-ce que le choix est valide ? powerset nec ?
		{
			subset[len] = set[i];	// fixe le choix 
			powerset(set, nb_set, subset, len + 1, sum + set[i], target, i + 1);
		}	
		i++;				//on avance
	}
}

int	main(int ac, char **av)
{
	int nb_set = ac - 2;
	int target = atoi(av[1]);// nombre cible

	int *subset = calloc(ac - 2, sizeof(int));// sous ensemble contenant les termes 
		if (!subset) return 1;

	int *set = calloc(ac - 2, sizeof(int));// ensemble de nombre donne en parametre
		if (!set) return 1;
	for (int i = 0; i + 2 < ac; i++)
		set[i] = atoi(av[i + 2]);

	int pos = 0;// position de l'index sur le set
	int sum = 0;// somme des termes
	int len = 0;// taille du sous-ensemble
	
	powerset(set, nb_set, subset, len, sum, target, pos);
}
