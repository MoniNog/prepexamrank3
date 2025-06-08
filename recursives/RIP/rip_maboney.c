#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_balanced(char *str, int index, int left_rem, int right_rem, int pair, char *buffer, int buffer_index)
{
    int len = strlen(str);
	if (index == len)
    {
        if (left_rem == 0 && right_rem == 0 && pair == 0)
        {
            buffer[buffer_index] = '\0';
            printf("%s\n", buffer);
        }
        return;
    }
    if (str[index] == '(')
    {
        if (left_rem > 0)
        {
            buffer[buffer_index] = ' ';
            generate_balanced(str, index + 1, left_rem - 1, right_rem, pair, buffer, buffer_index + 1);
        }
        buffer[buffer_index] = '(';
        generate_balanced(str, index + 1, left_rem, right_rem, pair + 1, buffer, buffer_index + 1);
    }
    else if (str[index] == ')')
    {
        if (right_rem > 0)
        {
            buffer[buffer_index] = ' ';
            generate_balanced(str, index + 1, left_rem, right_rem - 1, pair, buffer, buffer_index + 1);
        }
        if (pair > 0)
        {
            buffer[buffer_index] = ')';
            generate_balanced(str, index + 1, left_rem, right_rem, pair - 1, buffer, buffer_index + 1);
        }
    }
    else
    {
        buffer[buffer_index] = str[index];
        generate_balanced(str, index + 1, left_rem, right_rem, pair, buffer, buffer_index + 1);
    }
}

void count_invalid_parantheses(char *str)
{
    int left_rem = 0;
    int right_rem = 0;
	int len = strlen(str);
    int i = 0;
    while (i < len)
    {
        if (str[i] == '(')
            left_rem++;
        else if (str[i] == ')')
        {
            if (left_rem > 0)
                left_rem--;
        	else
                right_rem++;
        }
        i++;
    }

    char buffer[len + 1];
    generate_balanced(str, 0, left_rem, right_rem, 0, buffer, 0);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    count_invalid_parantheses(argv[1]);
    return 0;
}
