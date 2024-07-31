#include <libc.h>
#include <minishell.h>

int dschecker(char *str, int *index, char c)
{
    (*index)++;
    while (str[*index])
    {
        if (str[*index] == c)
            return(1);
        (*index)++;
    }
    return(0);
}
int main(int ac, char **env)
{
    char *str = "\" heeey ' \" '";
    printf("%s\n",str);
    int b;
    int i = 0;
    char c;

    b = 0;
    while(str[i])
    {
        if (str[i] == '\"' || str[i] == '\'')
        {
            c = str[i];
            if (!dschecker(str, &i , str[i]))
            {
                printf("sytax error near to %c\n",c);
            }
        }
        i++;
    }
}