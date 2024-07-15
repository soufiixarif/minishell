/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 06:31:01 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/15 17:44:56 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **ft_setenv(t_minishell *minishell)
{
	char	**env;
	char	*path;

	env = (char **)ft_malloc(minishell, &minishell->global, sizeof (char *) * 4);
	path = getcwd(NULL,0);
	env[0] = ft_strjoin(minishell,  "PWD=", path);
	free(path);
	env[1] = ft_strjoin(minishell, "SHLVL=",ft_itoa(minishell, minishell->shlvl));
	env[2] = ft_strdup(minishell, &minishell->global, "_=/usr/bin/env");
	env[3] = NULL;
	return(env);
}
