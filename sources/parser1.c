/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:55:39 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/07 13:17:15 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_syntax_err	s_quote(char *line)
{
	int				i;
	int				d;
	t_syntax_err	syntx_err;

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

t_syntax_err	d_quote(char *line)
{
	int				i;
	int				s;
	t_syntax_err	syntx_err;

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

void	open_heredocs(char *line, int n)
{
	int	i;
	
	i = 0;
	while (i < n)
	{
		if (line[i] == '<' && line[i + 1] == '<' && line[i + 2])
		{
			printf("herdoc open\n");
		}
		i++;
	}	
}

void	issyntax_err(char *line)
{
	int	i;
	t_syntax_err syntx_err1;
	t_syntax_err syntx_err2;

	syntx_err1 = s_quote(line);
	syntx_err2 = d_quote(line);

	i = 0;
	if (syntx_err1.bool == 1)
	{
		open_heredocs(line, syntx_err1.index);
		printf("syntax error '\n");
	}
	if (syntx_err2.bool == 1)
	{
		open_heredocs(line, syntx_err2.index);
		printf("syntax error \"\n");
	}
}

// int	is_spaces(char *line, int *i)
// {
// 	(*i) += 2;
// 	while (line[*i] && (line[*i] == ' ' || line[*i] == '\t'))
// 	{
// 		(*i)++;
// 	}
// 	if (line [*i] && line[*i] != '<' && line[*i] != '>' && line[*i] != '|')
// 		return (1);
// 	else
// 		return (0);
// }


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



void	parser(t_token **token, char *line)
{
	issyntax_err(line);
	ft_tokenizer(token, line);
	// printf("here\n");
}

