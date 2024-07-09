/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 07:59:55 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/09 10:34:11 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	res = malloc(getlen_blank(line, i) + 1);
	while (line[i] && ft_isblank(line[i]))
	{
		res[j] = line[i];
		j++;
		i++;
	}
	res[j] = '\0';
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
	res = malloc(getlen_op(line, i) + 1);
	while (line[i] && ft_isoperator(line[i]))
	{
		res[j] = line[i];
		j++;
		i++;
	}
	res[j] = '\0';
	*index = i;
	return (res);
}

char	*get_pipe(char *line, int *index)
{
	int		i;
	int		j;
	char	*res;

	i = *index;
	j = 0;
	res = malloc(getlen_pipe(line, i) + 1);
	while (ft_ispipe(line[i]))
	{
		res[j] = line[i];
		j++;
		i++;
	}
	res[j] = '\0';
	*index = i;
	return (res);
}

char	*get_in(char *line, int *index)
{
	int		i;
	int		j;
	char	*res;

	i = *index;
	j = 0;
	res = malloc(getlen_in(line, i) + 1);
	while (ft_isin(line[i]))
	{
		res[j] = line[i];
		j++;
		i++;
	}
	res[j] = '\0';
	*index = i;
	return (res);
}

char	*get_out(char *line, int *index)
{
	int		i;
	int		j;
	char	*res;

	i = *index;
	j = 0;
	res = malloc(getlen_out(line, i) + 1);
	while (ft_isout(line[i]))
	{
		res[j] = line[i];
		j++;
		i++;
	}
	res[j] = '\0';
	*index = i;
	return (res);
}

char	*get_herdoc(char *line, int *index)
{
	int		i;
	int		j;
	char	*res;

	i = *index;
	j = 0;
	res = malloc(3);
	ft_isin(line[i]);
	res[0] = '<';
	res[1] = '<';
	res[2] = '\0';
	i++;
	*index = i;
	return (res);
}

char	*get_append(char *line, int *index)
{
	int		i;
	int		j;
	char	*res;

	i = *index;
	j = 0;
	res = malloc(3);
	ft_isout(line[i]);
	res[0] = '>';
	res[1] = '>';
	res[2] = '\0';
	i++;
	*index = i;
	return (res);
}

char	*get_exp(char *line, int *index)
{
	int		i;
	int		j;
	char	*res;

	i = *index;
	j = 0;
	res = malloc(getlen_exp(line, i) + 1);
	while (line[i] && ft_isexpand(line[i]))
	{
		res[j] = line[i];
		j++;
		i++;
	}
	res[j] = '\0';
	*index = i;
	return (res);
}

char	*get_sq(char *line, int *index)
{
	int		i;
	int		j;
	char	*res;

	i = *index;
	j = 0;
	res = malloc(getlen_sq(line, i) + 1);
	res[j] = line[i];
	i++;
	j++;
	while (!ft_issnglqs(line[i]))
	{
		res[j] = line[i];
		j++;
		i++;
	}
	res[j] = line[i];
	i++;
	j++;
	res[j] = '\0';
	*index = i;
	return (res);
}
char	*get_dq(char *line, int *index)
{
	int		i;
	int		j;
	char	*res;

	i = *index;
	j = 0;
	res = malloc(getlen_dq(line, i) + 1);
	res[j] = line[i];
	i++;
	j++;
	while (!ft_isdblqs(line[i]))
	{
		res[j] = line[i];
		j++;
		i++;
	}
	res[j] = line[i];
	i++;
	j++;
	res[j] = '\0';
	*index = i;
	return (res);
}
