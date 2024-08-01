/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:50:23 by sarif             #+#    #+#             */
/*   Updated: 2024/07/29 23:17:30 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **ft_setenv(t_minishell *minishell)
{
	char	**env;
	char	*path;

	minishell->env_checker = false;
	env = (char **)ft_malloc(minishell, &minishell->global, sizeof (char *) * 5);
	env[0] = ft_strjoin(minishell, "PATH=","/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin");
	path = getcwd(NULL,0);
	env[1] = ft_strjoin(minishell,  "PWD=", path);
	free(path);
	env[2] = ft_strjoin(minishell, "SHLVL=",ft_itoa(minishell, minishell->shlvl));
	env[3] = ft_strdup(minishell, &minishell->global, "_=/usr/bin/env");
	env[4] = NULL;
	return(env);
}
