/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:06:16 by kelmounj          #+#    #+#             */
/*   Updated: 2024/08/01 14:27:30 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/minishell.h"

void	helper_del(t_minishell *msh, t_tokens *tkn, t_tokens *tkn2, char *t)
{
	bool	b;

	b = false;
	while (tkn2 && (tkn2->type == BLANK))
		tkn2 = tkn2->next;
	if (tkn2->type == TEXT || tkn2->type == EXP
		|| tkn2->type == S_QUOTE || tkn2->type == D_QUOTE)
	{
		while (tkn2 && (tkn2->type == TEXT || tkn2->type == EXP
				|| tkn2->type == S_QUOTE || tkn2->type == D_QUOTE))
		{
			if (tkn2->type == D_QUOTE)
				b = true;
			(1) && (t = ft_strjoin(msh, t, tkn2->token), tkn2 = tkn2->next);
		}
		tkn = tkn->next;
		tkn->token = t;
		if (b == true)
			tkn->type = Q_DEL;
		else
			tkn->type = DEL;
		tkn->next = tkn2;
	}
}

void	get_del(t_minishell *msh)
{
	t_tokens	*token;
	t_tokens	*token2;
	char		*tmp;

	tmp = ft_strdup(msh, &msh->local, "");
	token = msh->tokens;
	while (token)
	{
		if (token->next && token->type == HERDOC)
		{
			token2 = token->next;
			helper_del(msh, token, token2, tmp);
		}
		tmp = ft_strdup(msh, &msh->local, "");
		token = token->next;
	}
}

bool	is_ambiguous(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			return (true);
		i++;
	}
	return (false);
}

void	expainding(t_minishell *minishell)
{
	t_tokens	*tmp_token;
	char		*tmp;

	tmp_token = minishell->tokens;
	while (tmp_token)
	{
		if (tmp_token->next && tmp_token->type == EXP)
		{
			tmp_token = tmp_token->next;
			if (tmp_token && (tmp_token->type == TEXT))
			{
				tmp = ft_getenv(tmp_token->token, minishell);
				if (is_ambiguous(tmp) == true)
					tmp_token->boole = true;
				tmp_token->token = ft_strdup(minishell, &minishell->local, tmp);
			}
		}
		tmp_token = tmp_token->next;
	}
}

char	*herexp(t_minishell *minishell, char *herdoc)
{
	int		i;
	int		j;
	char	*var;
	char	*val;

	i = 0;
	j = 0;
	var = NULL;
	while (herdoc[i])
	{
		if (herdoc[i] == '$')
		{
			i++;
			while (!ft_isexpand(herdoc[i]) && !ft_isblank(herdoc[i]))
			{
				var[j] = herdoc[i];
				i++;
				j++;
			}
			val = ft_getenv(var, minishell);
		}
		i++;
	}
	return (val);
}
