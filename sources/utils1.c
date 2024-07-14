/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:44:01 by kelmounj          #+#    #+#             */
/*   Updated: 2024/06/25 14:46:47 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dstlen = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (dstlen < dstsize && dst[dstlen])
		dstlen++;
	srclen = ft_strlen(src);
	if (!dst || !src)
		return (0);
	i = dstlen;
	while (j + dstlen + 1 < dstsize && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (dstlen + srclen);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < (dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;
// 	size_t	s1len;
// 	size_t	s2len;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	s1len = ft_strlen(s1);
// 	s2len = ft_strlen(s2);
// 	str = (char *)malloc((s1len + s2len) * sizeof(char) + 1);
// 	if (!str)
// 		return (NULL);
// 	i = ft_strlcpy(str, s1, s1len + s2len + 1);
// 	j = ft_strlcat(str, s2, s1len + s2len + 1);
// 	str[j] = '\0';
// 	return (str);
// }
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	str = malloc (len + 1);
	if (!str)
		return (NULL);
	while (i++, s1[i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
