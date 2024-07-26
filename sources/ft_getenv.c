/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 05:24:49 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/26 17:49:29 by kelmounj         ###   ########.fr       */
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
			return (ft_strtrim(minishell, tmp, " \t"));
		}
		i++;
	}
	tmp = ft_strdup(minishell, &minishell->global, "");
	return (tmp);
}
