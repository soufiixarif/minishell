/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:45:31 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/15 17:45:13 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_nbrlen(long nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		len++;
	}
	if (nbr == 0)
		len = 1;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(t_minishell *minishell, int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = (long)n;
	len = ft_nbrlen(nb);
	str = ft_malloc(minishell, &minishell->local, len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		nb = nb * -1;
		str[0] = '-';
	}
	while (nb > 0)
	{
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (str);
}
