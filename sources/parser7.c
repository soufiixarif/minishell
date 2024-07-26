/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:40:57 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/26 17:48:56 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_value(t_minishell *minishell, t_token **tmp_token, char *token, int *index)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	(*index)++;
	tmp = NULL;
	while (token[*index] && !ft_isexpand(token[*index]) && !ft_isblank(token[*index]))
	{
		tmp[i] = token[*index];
		i++;
		(*index)++;
	}
	if (ft_isexpand(token[*index]) || ft_isblank(token[*index]))
		(*index)--;
	str = ft_getenv(tmp, minishell);
	if (is_ambiguous(str) == TRUE)
		(*tmp_token)->boole = TRUE;
	return(ft_strtrim(minishell, str, " \t"));
	
}

bool	if_exp(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (true);
		i++;
	}
	return (false);
}

int	get_lenexp(char *token, int index)
{
	int		i;
	int		count;

	i = index;
	count = 0;
	while (token[i] && (token[i] != '$' &&  token[i] != ' '))
	{
		count++;
		i++;
	}
	return (count);
}

int	get_len(char *token, int index)
{
	int		i;
	int		count;

	i = index;
	count = 0;
	while (token[i] && ((token[i] != '$') || (token[i] == '$' && token[i + 1] == '$')
		|| (token[i] == '$' && !(token[i + 1]))))
	{
		count++;
		i++;
	}
	return (count);
}

void	qexp_handler(t_minishell *minishell)
{
	t_token *tmp_token;
	int		i;
	int		len;
	char	*tmp;
	char	*tmp2;
	char	*str;

	tmp_token = minishell->token;
	tmp = NULL;
	tmp2 = NULL;
	i = 0;
	len = 0;
	while (tmp_token)
	{
		if (tmp_token->type == D_QUOTE)
		{
			if (if_exp(tmp_token->token) == true)
			{
				while (tmp_token->token[i])
				{
					if (!ft_isexpand(tmp_token->token[i]) || (ft_isexpand(tmp_token->token[i]) && ft_isexpand(tmp_token->token[i + 1]))
						|| (ft_isexpand(tmp_token->token[i]) && !(tmp_token->token[i + 1])))
					{
						len =  get_len(tmp_token->token, i);
						tmp = ft_substr(minishell, tmp_token->token, i, len);
						i = i + len;
					}
					else if (tmp_token->token[i] == '$' && tmp_token->token[i + 1] != '$')
					{
						i++;
						str = ft_substr(minishell, tmp_token->token, i, get_lenexp(tmp_token->token, i));
						i = i + get_lenexp(tmp_token->token, i);
						tmp = ft_getenv(str, minishell);
						if (is_ambiguous(tmp) == TRUE)
							tmp_token->boole = TRUE;
					}
					tmp2 = ft_strjoin(minishell, tmp2, tmp);
				}
				tmp_token->token = tmp2;
			}
		}
		tmp_token = tmp_token->next;
	}
}
