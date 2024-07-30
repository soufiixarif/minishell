/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:11:48 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/30 03:17:12 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	else
		return (((unsigned char)s1[i] - (unsigned char)s2[i]));
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if(!s1 || !s2)
		return(-1);
	while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0)
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strdup(t_minishell *minishell, t_garbage **garbage, const char *s1)
{
	char	*p;
	int		i;
	int		len;

	i = -1;
	len = ft_strlen((char *)s1);
	p = ft_malloc(minishell, garbage, len + 1);
	while (++i < len && s1[i])
		*(p + i) = s1[i];
	*(p + i) = 0;
	return (p);
}
