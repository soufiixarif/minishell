/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 07:57:03 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/13 06:47:27 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	getlen_string(char *line, int index)
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
int	getlen_blank(char *line, int index)
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
int	getlen_op(char *line, int index)
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
int	getlen_pipe(char *line, int index)
{
	int		i;
	int		count;

	i = index;
	count = 0;
	while (line[i] && ft_ispipe(line[i]))
	{
		count++;
		i++;
	}
	return (count);
}

int	getlen_in(char *line, int index)
{
	int		i;
	int		count;

	i = index;
	count = 0;
	while (line[i] && ft_isin(line[i]))
	{
		count++;
		i++;
	}
	return (count);
}

int	getlen_out(char *line, int index)
{
	int		i;
	int		count;

	i = index;
	count = 0;
	while (line[i] && ft_isout(line[i]))
	{
		count++;
		i++;
	}
	return (count);
}

int	getlen_exp(char *line, int index)
{
	int		i;
	int		count;

	i = index;
	count = 0;
	while (line[i] && ft_isexpand(line[i]))
	{
		count++;
		i++;
	}
	return (count);
}

int	getlen_sq(char *line, int index)
{
	int	i;
	int	count;

	i = index;
	count = 0;
	// count++;
	i++;
	while (!ft_issnglqs(line[i]))
	{
		count++;
		i++;
	}
	// count++;
	return (count);
}
int	getlen_dq(char *line, int index)
{
	int	i;
	int	count;

	i = index;
	count = 0;
	// count++;
	i++;
	while (!ft_isdblqs(line[i]))
	{
		count++;
		i++;
	}
	// count++;
	return (count);
}
