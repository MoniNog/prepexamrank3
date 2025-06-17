#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void    print_array(int *a, int len)
{
    int i = 0;
    while (i < len)
    {
        printf("%i ", a[i]);
        i++;
    }
    printf("\n");
}

void powerset(  int target,
                int sum,
                int l_set,
                int *set,
                int *subset,
                int i_subset
)
{
    if (sum == target)
    {
        print_array(subset, i_subset);
        return ;
    }

    int i = 0;
    while (i < l_set)
    {
        if (sum + set[i] <= target)
        {
            subset[i_subset] = set[i];
            i_subset + 1;
            i + 1;
        }
        powerset(target, sum + set[i], l_set, set, subset, i_subset);
        i++;
    }
}


int main(int ac, char **av)
{
    int target = atoi(av[1]);
    int sum = 0;
    int l_set = ac - 2;

    int *set = calloc(l_set, sizeof(int));
        if (!set)   return 1;
    int *subset = calloc(l_set, sizeof(int));
        if (!subset)   return 1;
    
    powerset(target, sum, l_set, set, subset, 0);

    free (set);
    free (subset);
}