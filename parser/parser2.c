/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:06:16 by kelmounj          #+#    #+#             */
/*   Updated: 2024/08/07 17:11:54 by kelmounj         ###   ########.fr       */
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

void	handel_ambg(t_minishell *minishell, t_tokens *tokens, char *val)
{
	t_tokens	*tmp_t;
	t_tokens	*new;
	char		*var;
	char		**splited;
	int			i;

	if (tokens->next)
		tmp_t = tokens->next;
	var = ft_strdup(minishell, &minishell->local, tokens->token);
	splited = ft_split(val, ' ');
	i = 0;
	tokens->next = NULL;
	tokens->ambg = ft_strdup(minishell, &minishell->local, var);
	tokens->token = ft_strdup(minishell, &minishell->local, splited[i++]);
	while (splited[i])
	{
		new = ft_lstnew(minishell, splited[i], TEXT);
		new->boole = true;
		new->ambg = ft_strdup(minishell, &minishell->local, var);
		ft_lstadd_back(&tokens, new);
		i++;
	}
	while (tokens)
		tokens = tokens->next;
	tokens = tmp_t;
}

void	expainding(t_minishell *minishell)
{
	t_tokens	*tmp_token;
	t_tokens	*tmp_token2;
	char		*tmp;

	tmp_token = minishell->tokens;
	while (tmp_token)
	{
		tmp_token2 = tmp_token;
		if (tmp_token2->next && tmp_token2->next->next && tmp_token2->next->type == EXP && tmp_token2->next->next->type == TEXT)
		{
			tmp_token2 = tmp_token2->next->next;
				tmp = ft_getenv(tmp_token2->token, minishell);
				if (is_ambiguous(tmp) == true)
				{
					tmp_token2->boole = true;
					handel_ambg(minishell, tmp_token2, tmp);
				}
				tmp_token2->token = ft_strdup(minishell, &minishell->local, tmp);
			tmp_token->next = tmp_token2;
		}
		tmp_token = tmp_token->next;
	}
}

// char	*herexp(t_minishell *minishell, char *herdoc)
// {
// 	int		i;
// 	int		j;
// 	char	*var;
// 	char	*val;

// 	i = 0;
// 	j = 0;
// 	var = NULL;
// 	val = NULL;
// 	while (herdoc[i])
// 	{
// 		if (herdoc[i] == '$')
// 		{
// 			i++;
// 			while (!ft_isexpand(herdoc[i]) && !ft_isblank(herdoc[i]))
// 			{
// 				var[j] = herdoc[i];
// 				i++;
// 				j++;
// 			}
// 			val = ft_getenv(var, minishell);
// 		}
// 		i++;
// 	}
// 	return (val);
// }

static int	lnx(char *token, int index)
{
	int		i;
	int		count;

	i = index;
	count = 0;
	while (token[i] && (token[i] != '$' && token[i] != ' '))
	{
		count++;
		i++;
	}
	return (count);
}

static int	get_len(char *token, int index)
{
	int		i;
	int		count;

	i = index;
	count = 0;
	while (token[i] && ((token[i] != '$')
			|| (token[i] == '$' && token[i + 1] == '$')
			|| (token[i] == '$' && !(token[i + 1]))))
	{
		count++;
		i++;
	}
	return (count);
}

char	*herexp(t_minishell *msh, char *herdoc)
{
	char		*tmp;
	char		*tmp2;
	int			i;
	int			len;
	char		*str;

	tmp = ft_strdup(msh, &msh->local, "");
	tmp2 = ft_strdup(msh, &msh->local, "");
	(1) && (i = 0, len = 0);
	while (herdoc[i])
	{
		if (!ft_isexpand(herdoc[i]) || (ft_isexpand(herdoc[i])
				&& ft_isexpand(herdoc[i + 1]))
			|| (ft_isexpand(herdoc[i])
				&& !(herdoc[i + 1])))
			(1) && (len = get_len(herdoc, i),
					tmp = _sub(msh, herdoc, i, len), i = i + len);
		else if (herdoc[i] == '$' && herdoc[i + 1] != '$')
		{
			(1) && (i++, str = _sub(msh, herdoc, i, lnx(herdoc, i)),
			i = i + lnx(herdoc, i), tmp = ft_getenv(str, msh));
		}
		tmp2 = ft_strjoin(msh, tmp2, tmp);
	}
	return(tmp2);
}
