/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:47:16 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/26 22:48:15 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;
	// int		len;

	// len = ft_strlen(s);
	ptr = (char *)s;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{
			return (ptr + i);
		}
		i++;
	}
	if ((unsigned char)c == 0)
		return (ptr + i);
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n < 1)
	{
		return (0);
	}
	while (i < n 
		&& (*(unsigned char *)(s1 + i)) == (*(unsigned char *)(s2 + i)))
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((*(unsigned char *)(s1 + i)) - (*(unsigned char *)(s2 + i)));
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == (void *)0 && src == (void *)0)
		return (dst);
	if (ft_memcmp(dst, src, n) == 0)
		return (dst);
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}

char	*ft_strtrim(t_minishell *minishell, char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*str;
	int		size;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	len = ft_strlen(s1);
	if (i > len - 1)
		return (ft_strdup(minishell, &minishell->local, ""));
	while (len > 0 && ft_strchr(set, s1[len]))
		len--;
	size = len - i + 1;
	str = (char *)malloc(size * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str = ft_memcpy(str, (s1 + i), size);
	str[size] = '\0';
	return (str);
}

char	*ft_substr(t_minishell *minishell, char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	n;

	i = 0;
	if (!s)
		return (NULL);
	n = ft_strlen(s);
	if (n < start)
		return (ft_strdup(minishell, &minishell->local, ""));
	if (len > n - start)
		len = n - start;
	str = ft_malloc(minishell, &minishell->local, (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}