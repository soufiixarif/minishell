/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:06:16 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/15 18:22:22 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_del(t_minishell *minishell)
{
	t_token	*tmp_token;
	t_token	*tmp_token2;
	char	*tmp;

	tmp_token = minishell->token;
	while (tmp_token)
	{
		if (tmp_token->type == HERDOC)
		{
			tmp_token2 = tmp_token->next;
			while (tmp_token2->type == TEXT || tmp_token2->type == EXP || tmp_token2->type == S_QUOTE || tmp_token2->type == D_QUOTE)
			{
				tmp = ft_strjoin(minishell, tmp, tmp_token2->token);
				tmp_token2 = tmp_token2->next;
			}
		}
	}
}