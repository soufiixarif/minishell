/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:40:57 by kelmounj          #+#    #+#             */
/*   Updated: 2024/08/01 14:51:34 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_value(t_minishell *minishell, t_tokens **tmp_token, char *token, int *index)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(minishell, &minishell->local, "");
	(*index)++;
	while (token[*index] && !ft_isexpand(token[*index]))
	{
		tmp[i] = token[*index];
		i++;
		(*index)++;
	}
	(*index)--;
	str = ft_getenv(tmp, minishell);
	if (is_ambiguous(str) == true)
		(*tmp_token)->boole = true;
	return(ft_strtrim(minishell, str, " \t"));
	
}

void	qexp_handler(t_minishell *minishell)
{
	t_tokens *tmp_token;
	char	*tmp;
	int		i;
	int		j;
	// int		count;

	i = 0;
	j = 0;
	// count = 0;
	tmp = ft_strdup(minishell, &minishell->local, "");
	tmp_token = minishell->tokens;
	while (tmp_token)
	{
		if (tmp_token->type == D_QUOTE)
		{
			while (tmp_token->token[i])
			{
				if (!ft_isexpand(tmp_token->token[i]) || (ft_isexpand(tmp_token->token[i]) && ft_isexpand(tmp_token->token[i + 1])))
					tmp[j++] = tmp_token->token[i];
				else if (tmp_token->token[i] == '$' && tmp_token->token[i + 1] != '$')
				{
					tmp = ft_strjoin(minishell, tmp, get_value(minishell, &tmp_token, tmp_token->token, &i));
					j = ft_strlen(tmp);
				}
				i++;
			}
			tmp_token->token = tmp;
		}
		tmp_token = tmp_token->next;
	}
}

