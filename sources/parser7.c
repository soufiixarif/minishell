/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:40:57 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/15 14:15:28 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	Qexp_handler(t_minishell *minishell)
{
	t_token *tmp_token;
	int		i;

	i = 0;
	tmp_token = minishell->token;
	while (tmp_token)
	{
		if (tmp_token->type == D_QUOTE)
		{
			while (tmp_token->token[i])
			{
				if (tmp_token->token[i] == '$')
					tmp_token->type = Q_EXP;
				i++;
			}
		}
		tmp_token = tmp_token->next;
	}
}

// void	concat_exp(t_minishell *minishell)
// {
// 	t_token	*tmp_token;
// 	t_token	*tmp_token;

// 	tmp_token = minishell->token;
// 	while (tmp_token)
// 	{
// 		if (tmp_token->type == EXP)
// 		{
			
// 		}
// 	}
// }
