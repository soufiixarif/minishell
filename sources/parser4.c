/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 07:59:55 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/15 14:05:12 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *get_string(t_minishell *minishell, char *line, int *index)
{
	int		i;
	int		j;
	char	*res;

	i = *index;
	j = 0;
	res = ft_malloc(minishell, &minishell->local, getlen_string(line, i) + 1);
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

char	*get_blank(t_minishell *minishell, char *line, int *index)
{
	int		i;
	int		j;
	char	*res;

	i = *index;
	j = 0;
	res = ft_malloc(minishell, &minishell->local, getlen_blank(line, i) + 1);
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
char	*get_op(t_minishell *minishell, char *line, int *index)
{
	int		i;
	int		j;
	char	*res;

	i = *index;
	j = 0;
	res = ft_malloc(minishell, &minishell->local, getlen_op(line, i) + 1);
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

char	*get_pipe(t_minishell *minishell, char *line, int *index)
{
	int		i;
	int		j;
	char	*res;

	i = *index;
	j = 0;
	res = ft_malloc(minishell, &minishell->local, getlen_pipe(line, i) + 1);
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

char	*get_in(t_minishell *minishell, char *line, int *index)
{
	int		i;
	int		j;
	char	*res;

	i = *index;
	j = 0;
	res = ft_malloc(minishell, &minishell->local, getlen_in(line, i) + 1);
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

char	*get_out(t_minishell *minishell, char *line, int *index)
{
	int		i;
	int		j;
	char	*res;

	i = *index;
	j = 0;
	res = ft_malloc(minishell, &minishell->local, getlen_out(line, i) + 1);
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

char	*get_herdoc(t_minishell *minishell, char *line, int *index)
{
	int		i;
	char	*res;

	i = *index;
	res = ft_malloc(minishell, &minishell->local, 3);
	ft_isin(line[i]);
	res[0] = '<';
	res[1] = '<';
	res[2] = '\0';
	i++;
	*index = i;
	return (res);
}

char	*get_append(t_minishell *minishell, char *line, int *index)
{
	int		i;
	char	*res;

	i = *index;
	res = ft_malloc(minishell, &minishell->local, 3);
	ft_isout(line[i]);
	res[0] = '>';
	res[1] = '>';
	res[2] = '\0';
	i++;
	*index = i;
	return (res);
}

char	*get_exp(t_minishell *minishell, int *index)
{
	int		i;
	int		j;
	char	*res;

	i = *index;
	j = 0;
	res = ft_malloc(minishell, &minishell->local, 2);
	res[0] = '$';
	res[1] = '\0';
	i++;
	*index = i;
	return (res);
}

char	*get_sq(t_minishell *minishell, char *line, int *index)
{
	int		i;
	int		j;
	char	*res;

	i = *index;
	j = 0;
	res = ft_malloc(minishell, &minishell->local, getlen_sq(line, i) + 1);
	i++;
	while (!ft_issnglqs(line[i]))
	{
		res[j] = line[i];
		j++;
		i++;
	}
	i++;
	res[j] = '\0';
	*index = i;
	return (res);
}
char	*get_dq(t_minishell *minishell, char *line, int *index)
{
	int		i;
	int		j;
	char	*res;

	i = *index;
	j = 0;
	res = ft_malloc(minishell, &minishell->local, getlen_dq(line, i) + 1);
	i++;
	while (!ft_isdblqs(line[i]))
	{
		res[j] = line[i];
		j++;
		i++;
	}
	i++;
	res[j] = '\0';
	*index = i;
	return (res);
}
