/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 01:14:32 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/31 11:36:17 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/minishell.h"

bool	ft_tokenizer0(t_minishell *minishell, char *line, t_tokens *tmp_token, int *i)
{
	bool	b;

	b = false;
	if (ft_isblank(line[*i]))
	{
		tmp_token = ft_lstnew(minishell, get_blank(minishell, line, *(&i)), BLANK);
		ft_lstadd_back(&minishell->tokens, tmp_token);
	}
	else if (ft_isoperator(line[*i]))
	{
		b = handle_op(minishell, line, *(&i));
	}
	else if (ft_isexpand(line[*i]))
	{
		tmp_token = ft_lstnew(minishell, get_exp(minishell, *(&i)), EXP);
		ft_lstadd_back(&minishell->tokens, tmp_token);
	}
	return (b);
}

void	ft_tokenizer1(t_minishell *minishell, char *line, t_tokens *tmp_token, int *i)
{
	if (ft_isdblqs(line[*i]))
	{
		tmp_token = ft_lstnew(minishell, get_dq(minishell, line, *(&i)), D_QUOTE);
		ft_lstadd_back(&minishell->tokens, tmp_token);
	}
	else
	{
		tmp_token = ft_lstnew(minishell, get_sq(minishell, line,*(&i)), S_QUOTE);
			ft_lstadd_back(&minishell->tokens, tmp_token);
	}
}

bool	ft_tokenizer(t_minishell *minishell, char *line)
{
	int		i;
	bool b;
	t_tokens *tmp_token;

	(1) && (i = 0, b = false);
	while (line[i])
	{
		if (ft_isstring(line[i]))
		{
			tmp_token = ft_lstnew(minishell, get_string(minishell, line, &i), TEXT);
			ft_lstadd_back(&minishell->tokens, tmp_token);
			continue ;
		}
		else if (ft_issnglqs(line[i]) || ft_isdblqs(line[i]))
		{
			ft_tokenizer1(minishell, line, tmp_token, &i);
			continue ;
		}
		else
		{
			b = ft_tokenizer0(minishell, line, tmp_token, &i);
			if (b)
				return (b);
			else if (b == false)
				continue;
		}
	}
	return (b);
}
