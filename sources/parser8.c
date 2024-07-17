/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:06:16 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/17 08:30:47 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_del(t_minishell *minishell)
{
	t_token	*tmp_token;
	t_token	*tmp_token2;
	char	*tmp;

	tmp = ft_strdup(minishell, &minishell->local , "");
	tmp_token = minishell->token;
	while (tmp_token)
	{
		if (tmp_token->type == HERDOC)
		{
			tmp_token2 = tmp_token->next;
			while (tmp_token2 && (tmp_token2->type == BLANK))
				tmp_token2 = tmp_token2->next;
			if (tmp_token2->type == TEXT || tmp_token2->type == EXP || tmp_token2->type == S_QUOTE || tmp_token2->type == D_QUOTE)
			{
				while (tmp_token2 && (tmp_token2->type == TEXT || tmp_token2->type == EXP || tmp_token2->type == S_QUOTE || tmp_token2->type == D_QUOTE))
				{
					tmp = ft_strjoin(minishell, tmp, tmp_token2->token);
					tmp_token2 = tmp_token2->next;
				}
				tmp_token = tmp_token->next;
				tmp_token->token = tmp;
				tmp_token->type = DEL;
				tmp_token->next = tmp_token2;
			}
		}
		tmp = ft_strdup(minishell, &minishell->local , "");
		tmp_token = tmp_token->next;
	}
}
