/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:55:39 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/19 08:37:11 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_syn_err	s_quote(char *line)
{
	int				i;
	int				d;
	t_syn_err	syntx_err;

	i = 0;
	d = 0;
	syntx_err.bool = 0;
	syntx_err.index = 0;
	while (line[i])
	{
		if (line[i]	== '"')
			d = !d;
		if (line[i] == '\'' && d == 0)
		{
			syntx_err.bool = !syntx_err.bool;
			syntx_err.index = i;
		}
		i++;
	}
	return (syntx_err);
}

t_syn_err	d_quote(char *line)
{
	int				i;
	int				s;
	t_syn_err	syntx_err;

	i = 0;
	s = 0;
	syntx_err.bool = 0;
	syntx_err.index = 0;
	while (line[i])
	{
		if (line[i]	== '\'')
			s = !s;
		if (line[i] == '"' && s == 0)
		{
			syntx_err.bool = !syntx_err.bool;
			syntx_err.index = i;
		}
		i++;
	}
	return (syntx_err);
}

int	is_del(char *line, int i, int n)
{
	i += 2;
	while (i < n && line[i] && (line[i] == ' ' || line[i] == '\t'))
	{
		i++;
	}
	if (line [i] && line[i] != '<' && line[i] != '>' && line[i] != '|' && i != n)
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
		if (line[i]	== '"' && !s)
			d = !d;
		if (line[i]	== '\'' && !d)
			s = !s;
		if (s == 0 && d == 0 && is_del(line, i, n) && line[i] == '<' && line[i + 1] == '<' && line[i + 2])
		{
			i = ft_openhd(minishell, line, &i);
		}
		i++;
	}
}

void	issyntax_err(t_minishell *minishell, char *line)
{
	t_syn_err syntx_err1;
	t_syn_err syntx_err2;

	syntx_err1 = s_quote(line);
	syntx_err2 = d_quote(line);
	if (syntx_err1.bool == 1)
	{
		open_heredocs(minishell, line, syntx_err1.index);
		printf("minishell: syntax error near unexpected token '\n");
	}
	if (syntx_err2.bool == 1)
	{
		open_heredocs(minishell, line, syntx_err2.index);
		printf("minishell: syntax error near unexpected token \"\n");
	}
}

void	parser(t_minishell *minishell, char *line)
{
	issyntax_err(minishell, line);
	ft_tokenizer(minishell, line);
	token_handler(minishell);
}














// int	heredoc(char *line)
// {
// 	int	i;
// 	int	s;
// 	int	d;

// 	i = 0;
// 	s = 0;
// 	d = 0;
// 	while (line[i])
// 	{
// 		if (line[i]	== '"')
// 			d = !d;
// 		if (line[i]	== '\'')
// 			s = !s;
// 		if (s == 0 && d == 0 && line[i] == '<' && line[i + 1] == '<' && !is_spaces(line, &i))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

