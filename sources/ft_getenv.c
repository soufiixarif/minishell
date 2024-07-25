/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 05:24:49 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/24 23:03:12 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *var, t_minishell *minishell)
{
	char	*tmp;
	size_t	len;
	int		check;
	int		i;

	i = 0;
	len = ft_strlen(var);
	while (minishell->env[i])
	{
		tmp = ft_strdup(minishell, &minishell->global, minishell->env[i]);
		check = ft_strncmp(var, minishell->env[i], ft_strlen(var));
		if (!check && minishell->env[i][len] == '=')
		{
			tmp = tmp + len + 1;
			return (tmp);
		}
		i++;
	}
	tmp = ft_strdup(minishell, &minishell->global, "");
	return (ft_strtrim(minishell, tmp, " \t"));
}
