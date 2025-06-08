#include <unistd.h>

void    rip(char *str, char *new, int left, int right, int i, int j, int open)
{
    if (!str[i])
    {
        if (left == 0 && right == 0 && open == 0)
        {
            new[j] = '\0';
            i = 0;
            while (new[i])
            {
                write(1, &new[i], 1);
                i++;
            }
            write(1, "\n", 1);
        }
        return ;
    }
    if (str[i] == '(')
    {
        if (left > 0) // Retirer d'abord
        {
            new[j] = ' ';
            rip(str, new, left - 1, right, i + 1, j + 1, open);
        }
        new[j] = '('; // Puis garder
        rip(str, new, left, right, i + 1, j + 1, open + 1);
    }
    else if (str[i] == ')')
    {
        if (right > 0) // Retirer d'abord
        {
            new[j] = ' ';
            rip(str, new, left, right - 1, i + 1, j + 1, open);
        }
        if (open > 0) // Puis fermer une paire
        {
            new[j] = ')';
            rip(str, new, left, right, i + 1, j + 1, open - 1);
        }
    }
}

int    main(int ac, char **av)
{
    int        i;
    int        left;
    int        right;
    char    new[100];

    if (ac == 1)
        return (0);
    if (ac < 1 || ac > 2)
        return (1);
    i = 0;
    left = 0;
    right = 0;
    while (i < 100)
        new[i++] = '\0';
    i = 0;
    while (av[1][i])
    {
        if (av[1][i] == '(')
        {
            left++;
        }
        else if (av[1][i] == ')')
        {
            right++;
            if (left > 0)
            {
                left--;
                right--;
            }
        }
        i++;
    }
    rip(av[1], new, left, right, 0, 0, 0);
    return (0);
}