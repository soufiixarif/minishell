/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfullenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:50:02 by sarif             #+#    #+#             */
/*   Updated: 2024/07/18 04:49:42 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_countline(char **environ)
{
    int i;

    i = 0;
    while (environ[i])
    {
        i++;
    }
    return(i);
}

char **ft_getfullenv(t_minishell *minishell)
{
    extern char **environ;
    char        **env;
    char        **lvl;
    int         i;

    i = 0;
    minishell->shlvl = 1;
    if(!environ || !*environ)
        env = ft_setenv(minishell);
    else
    {
        env = (char **)ft_malloc(minishell, &minishell->global, sizeof (char *) * ft_countline(environ));
        while (environ[i])
        {
            if(!ft_strncmp("SHLVL=",environ[i],6))
            {
                lvl = ft_split(environ[i],'=');
                minishell->shlvl = ft_atoi(lvl[1]) + 1;
                environ[i] = ft_strjoin(minishell ,"SHLVL=",ft_itoa(minishell ,minishell->shlvl));
            }
            env[i] = ft_strdup(minishell, &minishell->global, environ[i]);
            i++;
        }
        env[i] = NULL;
    }
    return(env);
}
