/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:50:23 by sarif             #+#    #+#             */
/*   Updated: 2024/07/23 08:24:15 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **ft_setenv(t_minishell *minishell)
{
	char	**env;
	char	*path;

	minishell->env_checker = false;
	env = (char **)ft_malloc(minishell, &minishell->global, sizeof (char *) * 4);
	path = getcwd(NULL,0);
	env[0] = ft_strjoin(minishell,  "PWD=", path);
	free(path);
	env[1] = ft_strjoin(minishell, "SHLVL=",ft_itoa(minishell, minishell->shlvl));
	env[2] = ft_strdup(minishell, &minishell->global, "_=/usr/bin/env");
	env[3] = ft_strjoin(minishell, "PATH=","/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin");
	env[4] = NULL;
	return(env);
}
