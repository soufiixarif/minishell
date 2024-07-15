#include "minishell.h"

void execution(t_minishell *ms, char *line)
{
    int i = 0;
    if (!ft_strcmp(line,"env"))
    {
        while (ms->env[i])
        {
            printf("%s\n",ms->env[i]);
            i++;
        }
    }
}