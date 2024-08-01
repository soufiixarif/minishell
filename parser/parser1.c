/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:40:57 by kelmounj          #+#    #+#             */
/*   Updated: 2024/08/01 13:31:24 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/minishell.h"

// char	*get_value(t_minishell *msh, t_tokens **token_t, char *token, int *idx)
// {
// 	char	*str;
// 	char	*tmp;
// 	int		i;

// 	i = 0;
// 	(*idx)++;
// 	tmp = NULL;
// 	while (token[*idx] && !ft_isexpand(token[*idx]) && !ft_isblank(token[*idx]))
// 	{
// 		tmp[i] = token[*idx];
// 		i++;
// 		(*idx)++;
// 	}
// 	if (ft_isexpand(token[*idx]) || ft_isblank(token[*idx]))
// 		(*idx)--;
// 	str = ft_getenv(tmp, msh);
// 	if (is_ambiguous(str) == true)
// 		(*token_t)->boole = true;
// 	return(ft_strtrim(msh, str, " \t"));
// }

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

int	lnx(char *token, int index)
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

int	get_len(char *token, int index)
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

void	helper_qexp(t_minishell *msh, t_tokens *tkn)
{
	char		*tmp;
	char		*tmp2;
	int			i;
	int			len;
	char		*str;

	(1) && (tmp = NULL, tmp2 = NULL, i = 0, len = 0);
	while (tkn->token[i])
	{
		if (!ft_isexpand(tkn->token[i]) || (ft_isexpand(tkn->token[i])
				&& ft_isexpand(tkn->token[i + 1]))
			|| (ft_isexpand(tkn->token[i])
				&& !(tkn->token[i + 1])))
			(1) && (len = get_len(tkn->token, i),
					tmp = _sub(msh, tkn->token, i, len), i = i + len);
		else if (tkn->token[i] == '$' && tkn->token[i + 1] != '$')
		{
			(1) && (i++, str = _sub(msh, tkn->token, i, lnx(tkn->token, i)),
			i = i + lnx(tkn->token, i), tmp = ft_getenv(str, msh));
			if (is_ambiguous(tmp) == true)
				tkn->boole = true;
		}
		tmp2 = ft_strjoin(msh, tmp2, tmp);
	}
	tkn->token = tmp2;
}

void	qexp_handler(t_minishell *msh)
{
	t_tokens	*token_t;

	token_t = msh->tokens;
	while (token_t)
	{
		if (token_t->type == D_QUOTE)
		{
			if (if_exp(token_t->token) == true)
				helper_qexp(msh, token_t);
		}
		token_t = token_t->next;
	}
}
