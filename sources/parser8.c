/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:06:16 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/22 01:50:04 by kelmounj         ###   ########.fr       */
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
		if (tmp_token->next && tmp_token->type == HERDOC)
		{
			tmp_token2 = tmp_token->next;
			while (tmp_token2 && (tmp_token2->type == BLANK))
				tmp_token2 = tmp_token2->next;
			if (tmp_token2->type == TEXT || tmp_token2->type == EXP || tmp_token2->type == S_QUOTE || tmp_token2->type == D_QUOTE)
			{
				while (tmp_token2 && (tmp_token2->type == TEXT || tmp_token2->type == EXP || tmp_token2->type == S_QUOTE || tmp_token2->type == D_QUOTE))
					(1) && (tmp = ft_strjoin(minishell, tmp, tmp_token2->token), tmp_token2 = tmp_token2->next);
				(1) && (tmp_token = tmp_token->next , tmp_token->token = tmp, tmp_token->type = DEL, tmp_token->next = tmp_token2) ;
			}
		}
		tmp = ft_strdup(minishell, &minishell->local , "");
		tmp_token = tmp_token->next;
	}
}

t_bool	is_ambiguous(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			return(TRUE);
		i++;
	}
	return(FALSE);
}

void	expainding(t_minishell *minishell)
{
	
	t_token	*tmp_token;
	char	*tmp;

	tmp_token = minishell->token;
	while (tmp_token)
	{
		if (tmp_token->next && tmp_token->type == EXP)
		{
			tmp_token = tmp_token->next;
			if (tmp_token && (tmp_token->type == TEXT))
			{
				tmp = ft_getenv(tmp_token->token, minishell);
				if (is_ambiguous(tmp) == TRUE)
					tmp_token->bool = TRUE;
				tmp_token->token = ft_strdup(minishell, &minishell->local, tmp);
			}
		}
		tmp_token = tmp_token->next;
	}
}
