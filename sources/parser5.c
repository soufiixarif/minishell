/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:49:04 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/09 10:33:23 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	 handle_pipe(char *line, int index)
{
	int	i;

	i = index;
	i++;
	if (ft_isblank(line[i]))
	{
		while(ft_isblank(line[i]))
			i++;
		if(ft_ispipe(line[i]))	
			printf("syntax error near unexpected token1 `|'\n");
	}
	else if(ft_ispipe(line[i]))
		printf("syntax error near unexpected token2 `|'\n");
	else if (line[i] == '\0')
		printf("syntax error near unexpected token3 `|'\n");
}

void	handle_herdoc(char *line, int index)
{
	int		i;
	
	i = index;
	i++;
	if (line[i] == '|' || line[i] == '<' || line[i] == '>' || line[i] == '\0')
		printf("syntax error near unexpected token8 `|'\n");
	else if(ft_isblank(line[i]))
	{
		while(ft_isblank(line[i]))
			i++;
		if (line[i] == '|' || line[i] == '<' || line[i] == '>' || line[i] == '\0')
			printf("syntax error near unexpected token9 `|'\n");
	}
}

void	handle_in(t_token **token, char *line, int *index)
{
	int		i;
	t_token *tmp_token;
	
	i = *index;
	i++;
	if (line[i] == '<')
	{
		handle_herdoc(line, i);
		tmp_token = ft_lstnew(get_herdoc(line, &i), HERDOC);
		ft_lstadd_back(token, tmp_token);
		*index = i;
	}
	else if (line[i] == '|' || line[i] == '>' || line[i] == '\0')
		printf("syntax error near unexpected token4 `|'\n");
	else if(ft_isblank(line[i]))
	{
		while(ft_isblank(line[i]))
			i++;
		if (line[i] == '|' || line[i] == '<' || line[i] == '>' || line[i] == '\0')
			printf("syntax error near unexpected token5 `|'\n");
	}
}

void	handle_out(t_token **token, char *line, int *index)
{
	int		i;
	t_token *tmp_token;
	
	i = *index;
	i++;
	if (line[i] == '>')
	{
		handle_append(line,i);
		tmp_token = ft_lstnew(get_append(line, &i), APPEND);
		ft_lstadd_back(token, tmp_token);
		*index = i;
	}
	else if (line[i] == '|' || line[i] == '<' || line[i] == '\0')
		printf("syntax error near unexpected token6 `|'\n");
	else if(ft_isblank(line[i]))
	{
		while(ft_isblank(line[i]))
			i++;
		if (line[i] == '|' || line[i] == '<' || line[i] == '>' || line[i] == '\0')
			printf("syntax error near unexpected token7 `|'\n");
	}
}


void	handle_append(char *line, int index)
{
	int		i;
	
	i = index;
	i++;
	if (line[i] == '|' || line[i] == '<' || line[i] == '>' || line[i] == '\0')
		printf("syntax error near unexpected token8 `|'\n");
	else if(ft_isblank(line[i]))
	{
		while(ft_isblank(line[i]))
			i++;
		if (line[i] == '|' || line[i] == '<' || line[i] == '>' || line[i] == '\0')
			printf("syntax error near unexpected token9 `|'\n");
	}
}
