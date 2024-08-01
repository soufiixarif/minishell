/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:05:53 by kelmounj          #+#    #+#             */
/*   Updated: 2024/08/01 12:39:21 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/minishell.h"

int	is_del(char *line, int i, int n)
{
	i += 2;
	while (line[i] && i < n && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line [i] && line[i] != '<'
		&& line[i] != '>' && line[i] != '|' && i != n)
		return (1);
	else
		return (0);
}

void	open_heredocs(t_minishell *minishell, char *line, int n)
{
	int	i;
	int	s;
	int	d;

	s = 0;
	d = 0;
	i = 0;
	while (i < n)
	{
		if (line[i] == '"' && !s)
			d = !d;
		if (line[i] == '\'' && !d)
			s = !s;
		if (line[i] && line[i + 1] && line[i + 2] && s == 0 && d == 0
			&& is_del(line, i, n) && line[i] == '<' && line[i + 1] == '<')
		{
			i = ft_openhd_se(minishell, line, &i);
		}
		i++;
	}
}

int	dschecker(char *str, int *index, char c)
{
	(*index)++;
	while (str[*index])
	{
		if (str[*index] == c)
			return (1);
		(*index)++;
	}
	return (0);
}

bool	sd_handler(t_minishell *msh, char *line)
{
	int		i;
	int		store;
	char	c;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
		{
			c = line[i];
			store = i;
			if (!dschecker(line, &i, line[i]))
			{
				open_heredocs(msh, line, store);
				printf("minishell: syntax error near unexpected token %c\n", c);
				return (true);
			}
		}
		i++;
	}
	return (false);
}
