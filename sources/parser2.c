/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 01:14:32 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/08 06:31:06 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int getlen_string(char *line, int index)
{
	int		i;
	int		count;

	i = index;
	count = 0;
	while (line[i] && ft_isstring(line[i]))
	{
		count++;
		i++;
	}
	return (count);
}
int getlen_blank(char *line, int index)
{
	int		i;
	int		count;

	i = index;
	count = 0;
	while (line[i] && ft_isblank(line[i]))
	{
		count++;
		i++;
	}
	return (count);
}
int getlen_op(char *line, int index)
{
	int		i;
	int		count;

	i = index;
	count = 0;
	while (line[i] && ft_isoperator(line[i]))
	{
		count++;
		i++;
	}
	return (count);
}

char *get_string(char *line, int *index)
{
	int		i;
	int		j;
	char	*res;

	i = *index;
	j = 0;
	res = malloc(getlen_string(line, i) + 1);
	while (line[i] && ft_isstring(line[i]))
	{
		res[j] = line[i];
		j++;
		i++;
	}
	res[j] = '\0';
	*index = i;
	return (res);
}

char	*get_blank(char *line, int *index)
{
	int		i;
	int		j;
	char	*res;

	i = *index;
	j = 0;
	res = malloc(getlen_blank(line, i));
	while (line[i] && ft_isblank(line[i]))
	{
		res[j] = line[i];
		j++;
		i++;
	}
	*index = i;
	return (res);
}
char	*get_op(char *line, int *index)
{
	int		i;
	int		j;
	char	*res;

	i = *index;
	j = 0;
	res = malloc(getlen_op(line, i));
	while (line[i] && ft_isoperator(line[i]))
	{
		res[j] = line[i];
		j++;
		i++;
	}
	*index = i;
	return (res);
}

void	ft_tokenizer(t_token **token, char *line)
{
	int		i;
	t_token *tmp_token;

	i = 0;
	while (line[i])
	{
		if (ft_isstring(line[i]))
		{
			tmp_token = ft_lstnew(get_string(line, &i), 1);
			ft_lstadd_back(token, tmp_token);
			continue ;
		}
		if (ft_isblank(line[i]))
		{
			tmp_token = ft_lstnew(get_blank(line, &i), 2);
			ft_lstadd_back(token, tmp_token);
			continue ;
		}
		if (ft_isoperator(line[i]))
		{
			tmp_token = ft_lstnew(get_op(line, &i), 3);
			ft_lstadd_back(token, tmp_token);
			continue ;
		}
		i++;
	}
}