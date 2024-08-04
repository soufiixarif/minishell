/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 00:59:20 by sarif             #+#    #+#             */
/*   Updated: 2024/08/03 20:54:09 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/minishell.h"
#include <string.h>

int ft_isdigit(char c)
{
    return(c >= '0' && c <= '9');
}

int     check_invalid_id(char *str)
{
    if(ft_isdigit(*str))
        return(0);
    while(*str)
    {
        if (!(ft_isalnum(*str) || *str == '_'))
            return(0);
        str++;
    }
    return (1);
}
void    sort_env(char **env, int size)
{
     int i, j;
    char *temp;

    i = 0;
    while (i < size - 1) 
    {
        j = 0;
        while (j < size - 1) 
        {
            if (env[j] == NULL) 
            {
                temp = env[j];
                env[j] = env[j + 1];
                env[j + 1] = temp;
            } 
            else if (env[j + 1] != NULL && ft_strcmp(env[j], env[j + 1]) > 0) 
            {
                temp = env[j];
                env[j] = env[j + 1];
                env[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}
// void    sort_env(t_minishell *msh, int len)
// {
//     int i;
//     int j;
//     int swap;
//     char *tmp;

//     i = 0;
//     while(i < len - 1)
//     {
//         j = 0, swap = 0;
//         while(j < len - i - 1)
//         {
//             if(msh->env[j + 1] && (!msh->env[j] || ft_strcmp(msh->env[j], msh->env[j + 1]) > 0))
//             {
//                 tmp = msh->env[j + 1];
//                 msh->env[j + 1] = msh->env[j];
//                 msh->env[j] = tmp;
//                 swap = 1;
//             }
//             j++;
//         }
//         if(swap == 0)
//             break ;
//         i++;
//     }
// }
void    ft_unset(t_minishell *msh, t_cmd *cmd)
{
    int i;
    int len;
    int count_line;

    i = 0;
    if (cmd->av[1] && !check_invalid_id(cmd->av[1]))
    {
        printf("bash: unset: \'%s\': not a valid identifier\n", cmd->av[1]);
        return;   
    }
    len = ft_strlen(cmd->av[1]);
    count_line = ft_countline(msh->env);
    while(msh->env[i])
    {
        if(!ft_strncmp(cmd->av[1],msh->env[i],len) && msh->env[i][len] == '=')
        {
            msh->env[i] = NULL;
            sort_env(msh->env, count_line - 1);
            break;
        }
        i++;
    }
}
