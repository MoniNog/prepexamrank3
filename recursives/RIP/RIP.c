
void	try_open(char * line)
{
	if (*line=='(')
        try_close(line+1);
    else if (*line==')')
        line[0] = ' ';


}

int	try_close(char * line)
{
    if (*line==')')
        return 1;
}


int main(int ac, char **av)
{
	try_open(av[1]);
	return 0;
}