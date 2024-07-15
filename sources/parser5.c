/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:49:04 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/15 14:15:00 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	 handle_pipe(t_minishell *minishell, char *line, int index)
{
	int	i;

	i = index;
	i++;
	if (ft_isblank(line[i]))
	{
		while(ft_isblank(line[i]))
			i++;
		if(ft_ispipe(line[i]))
			syntax_errora(minishell, line, i);
	}
	else if(ft_ispipe(line[i]))
		syntax_errora(minishell, line, i);
	else if (line[i] == '\0')
		syntax_errora(minishell, line, i);
}

void	handle_in(t_minishell *minishell, char *line, int *index)
{
	int		i;
	t_token *tmp_token;
	
	i = *index;
	i++;
	if (line[i] == '<')
	{
		handle_herdoc(minishell, line, i);
		tmp_token = ft_lstnew(minishell ,get_herdoc(minishell, line, &i), HERDOC);
		ft_lstadd_back(&minishell->token, tmp_token);
		*index = i;
	}
	else if (line[i] == '|' || line[i] == '>' || line[i] == '\0')
		syntax_errorb(minishell, line, i);
	else if(ft_isblank(line[i]))
	{
		while(ft_isblank(line[i]))
			i++;
		if (line[i] == '|' || line[i] == '<' || line[i] == '>' || line[i] == '\0')
		syntax_errorb(minishell, line, i);
	}
}

void	handle_out(t_minishell *minishell, char *line, int *index)
{
	int		i;
	t_token *tmp_token;
	
	i = *index;
	i++;
	if (line[i] == '>')
	{
		handle_append(minishell, line,i);
		tmp_token = ft_lstnew(minishell ,get_append(minishell, line, &i), APPEND);
		ft_lstadd_back(&minishell->token, tmp_token);
		*index = i;
	}
	else if (line[i] == '|' || line[i] == '<' || line[i] == '\0')
		syntax_errorb(minishell, line, i);
	else if(ft_isblank(line[i]))
	{
		while(ft_isblank(line[i]))
			i++;
		if (line[i] == '|' || line[i] == '<' || line[i] == '>' || line[i] == '\0')
			syntax_errorb(minishell, line, i);
	}
}

void	handle_herdoc(t_minishell *minishell, char *line, int index)
{
	int		i;
	
	i = index;
	i++;
	if (line[i] == '|' || line[i] == '<' || line[i] == '>' || line[i] == '\0')
			syntax_errorb(minishell, line, i);
	else if(ft_isblank(line[i]))
	{
		while(ft_isblank(line[i]))
			i++;
		if (line[i] == '|' || line[i] == '<' || line[i] == '>' || line[i] == '\0')
			syntax_errorb(minishell, line, i);
	}
}

void	handle_append(t_minishell *minishell, char *line, int index)
{
	int		i;
	
	i = index;
	i++;
	if (line[i] == '|' || line[i] == '<' || line[i] == '>' || line[i] == '\0')
		syntax_errorb(minishell, line, i);
	else if(ft_isblank(line[i]))
	{
		while(ft_isblank(line[i]))
			i++;
		if (line[i] == '|' || line[i] == '<' || line[i] == '>' || line[i] == '\0')
			syntax_errorb(minishell, line, i);
	}
}
