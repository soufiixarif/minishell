/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfullenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 05:25:03 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/15 17:15:24 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int ft_countline(char **environ)
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
            env[i] = ft_strdup(minishell, &minishell->global, environ[i]);
            i++;
        }
        env[i] = NULL;
    }
    return(env);
}
