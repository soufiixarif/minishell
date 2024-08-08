/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:38:27 by kelmounj          #+#    #+#             */
/*   Updated: 2024/08/06 15:20:55 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(t_garbage **garbage, int boole)
{
	ft_garclear(garbage);
	if (boole)
	{
		write(2, "Allocation error\n", 17);
		exit(1);
	}
}

void	*ft_malloc(t_minishell *minishell, t_garbage **garbage, size_t size)
{
	t_garbage	*tmp_garbage;
	void		*new;

	tmp_garbage = NULL;
	new = malloc(size);
	if (!new)
		return (ft_free(&minishell->local, 0), ft_free(&minishell->global, 1), NULL);
	tmp_garbage = ft_garnew(minishell, new);
	ft_garadd_back(garbage, tmp_garbage);
	return (new);
}

// void fn()
// {
// 	system("leaks a.out");
// }

// int main()
// {
// 	atexit(fn);
// 	t_garbage *garbage;
// 	char *res;
	
// 	garbage = NULL;
// 	res = ft_malloc(&garbage, 10);
// 	res = ft_malloc(&garbage, 10);
// 	res = ft_malloc(&garbage, 10);
// 	res = ft_malloc(&garbage, 10);
// 	res = ft_malloc(&garbage, 10);
// 	res = ft_malloc(&garbage, 10);
// 	ft_free(&garbage, 0);
// }