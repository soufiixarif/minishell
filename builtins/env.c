/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 22:57:18 by sarif             #+#    #+#             */
/*   Updated: 2024/08/09 00:10:24 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/minishell.h"

static int check_env_path(t_minishell *msh)
{
    int i;
    int j;
    char **store;

    i = 0;
    while(msh->env[i])
    {
        if(!ft_strcmp("PATH",get_var(msh->env[i], false)))
        {
            store = ft_split(ft_get_value(msh->env[i]),':');
            if(!store)
                return(free(store),0);
            j = 0;
            while(store[j])
            {
                if(!ft_strcmp("/usr/bin",store[j]))
                    return(1);
                j++;
            }
        }
        i++;
    }
    return(0);
    
}
bool equalchr(char *str)
{
    while(*str)
    {
        if(*str == '=')
            return(true);
        str++;
    }
    return(false);
}

void    ft_env(t_minishell *msh)
{
    int i;

    i = 0;
    if(!check_env_path(msh))
        printf("minishell: env: command not found\n");
    else
    {
        while (msh->env[i])
        {
            if (!msh->env_checker && !ft_strncmp("PATH=",msh->env[i],5))
                i++;
            if (equalchr(msh->env[i]))
            {
                printf("%s",msh->env[i]);
                printf("\n");
            }
            i++;
        }   
    }
}
