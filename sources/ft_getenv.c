/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 05:24:49 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/17 16:53:47 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *var, t_minishell *minishell)
{
	char	*tmp;
	int		i;

	i = 0;
	while (minishell->env[i])
	{
		tmp = ft_strdup(minishell, &minishell->global, minishell->env[i]);
		if (ft_strncmp(var, minishell->env[i], ft_strlen(var)) == 0)
			return (tmp);
		i++;
	}
	tmp = ft_strdup(minishell, &minishell->global, "");
	return (ft_strtrim(minishell, tmp, " \t"));
}
