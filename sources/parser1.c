/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:55:39 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/02 09:10:42 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	s_quote(char *line)
{
	int	i;
	int open;
	int	d;

	i = 0;
	open = 0;
	d = 0;
	while (line[i])
	{
		if (line[i]	== '"')
			d = !d;
		if (line[i] == '\'' && d == 0)
			open = !open;
		i++;
	}
	if (open == 0)
		return (1);
	else 
		return (0);
}

int	d_quote(char *line)
{
	int	i;
	int open;
	int	s;

	i = 0;
	open = 0;
	s = 0;
	while (line[i])
	{
		if (line[i]	== '\'')
			s = !s;
		if (line[i] == '"' && s == 0)
			open = !open;
		i++;
	}
	if (open == 0)
		return (1);
	else
		return (0);
}

int	is_spaces(char *line, int *i)
{
	(*i) += 2;
	while (line[*i] && (line[*i] == ' ' || line[*i] == '\t'))
	{
		(*i)++;
	}
	if (line [*i] && line[*i] != '<' && line[*i] != '>' && line[*i] != '|')
		return (1);
	else
		return (0);
}



int	heredoc(char *line)
{
	int	i;
	int	s;
	int	d;

	i = 0;
	s = 0;
	d = 0;
	while (line[i])
	{
		if (line[i]	== '"')
			d = !d;
		if (line[i]	== '\'')
			s = !s;
		if (s == 0 && d == 0 && line[i] == '<' && line[i + 1] == '<' && !is_spaces(line, &i))
			return (0);
		i++;
	}
	return (1);
}

// void	open_heredocs(char *line)
// {
	//open all heredocs
// }

void	parser(char *line)
{
	if (!s_quote(line))
		printf("syntax error\n");
	if (!d_quote(line))
		printf("syntax error\n");
	if (!heredoc(line))
		printf("syntax error\n");
}



// int main(int ac, char **av)
// {
// 	printf("%d", heredoc(av[1]));
// }
