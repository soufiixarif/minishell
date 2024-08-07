/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tok.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:45:44 by kelmounj          #+#    #+#             */
/*   Updated: 2024/08/07 23:03:54 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	stick_tok(t_minishell *msh)
{
	t_tokens	*tmp_t;
	t_tokens	*tmp_t2;
	char		*tmp;

	(1) && (tmp = ft_strdup(msh, &msh->local, ""), tmp_t = msh->tokens);
	tmp_t2 = msh->tokens;
	while (tmp_t)
	{
		if (tmp_t->type == TEXT || tmp_t->type == S_QUOTE
			|| tmp_t->type == D_QUOTE || tmp_t->type == EXP)
		{
			tmp_t2 = tmp_t;
			while (tmp_t && (tmp_t->type == TEXT || tmp_t->type == S_QUOTE || tmp_t->type == D_QUOTE || tmp_t->type == EXP))
			{
				// printf("hna\t(%s)\t%u\n", tmp_t->token, tmp_t->type);
				tmp = ft_strjoin(msh, tmp, tmp_t->token);
				tmp_t = tmp_t->next;
			}
			// if (tmp_t && tmp_t->next &&  tmp_t->type == EXP && tmp_t->next->type == EXP)
			// {
			// 	while (tmp_t && tmp_t->type == EXP)
			// 	{
			// 		tmp = ft_strjoin(msh, tmp, tmp_t->token);
			// 		if (tmp_t->next && tmp_t->next->type == TEXT)
			// 			break;
			// 		tmp_t = tmp_t->next;
			// 	}
			// }
			// if (tmp_t && tmp_t->type == EXP && (tmp_t->next == NULL || tmp_t->next->type == BLANK))
			// 	(1) && (tmp = ft_strjoin(msh, tmp, tmp_t->token)
			// 		, tmp_t = tmp_t->next);
			(1) && (tmp_t2->token = tmp, tmp_t2->next = tmp_t, tmp = NULL);
		}
		if (tmp_t && tmp_t->next)
			tmp_t = tmp_t->next;
		else
			break;
	}
}

void	rm_exp(t_minishell *minishell)
{
	t_tokens	*tmp_token;

	tmp_token = minishell->tokens;
	while (tmp_token)
	{
		if (tmp_token->next && tmp_token->next->next && tmp_token->next->type == EXP && (tmp_token->next->next->type == D_QUOTE || tmp_token->next->next->type == S_QUOTE))
			tmp_token->next = tmp_token->next->next;
		else
			tmp_token = tmp_token->next;
	}
}

void	rm_blank(t_minishell *minishell)
{
	t_tokens	*tmp_token;

	tmp_token = minishell->tokens;
	while (tmp_token && tmp_token->type == BLANK)
		tmp_token = tmp_token->next;
	minishell->tokens = tmp_token;
	while (tmp_token)
	{
		if (tmp_token->next && tmp_token->next->type == BLANK)
			tmp_token->next = tmp_token->next->next;
		else
			tmp_token = tmp_token->next;
	}
}

void	fill_cmd(t_minishell *minishell)
{
	t_tokens	*token1;
	t_tokens	*token2;
	t_tokens	*token3;
	t_cmd		*cmd;
	int			index;

	(1) && (cmd = NULL, index = 0, token1 = minishell->tokens,
		token2 = minishell->tokens);
	while (token1)
	{
		while (token1 && token1->next && token1->next->type != PIPE)
			token1 = token1->next;
		token3 = token1;
		if (token1 && token1->next && token1->next->type == PIPE)
			token1 = token1->next->next;
		else if (token1)
			token1 = token1->next;
		token3->next = NULL;
		cmd = ft_newcmd(minishell, token2);
		cmd->c_idx = index++;
		ft_addcmd_back(&minishell->cmd, cmd);
		token2 = token1;
	}
}

void	token_cmd(t_minishell *minishell)
{
	t_cmd		*cmd;
	t_tokens	*tokens;

	cmd = minishell->cmd;
	while (cmd)
	{
		tokens = cmd->tokens;
		while (tokens)
		{
			tokens->cmd = cmd;
			tokens = tokens->next;
		}
		cmd = cmd->next;
	}
}

void	token_index(t_minishell *minishell)
{
	t_cmd		*cmd;
	t_tokens	*tokens;
	int			index;

	index = 0;
	cmd = minishell->cmd;
	while (cmd)
	{
		tokens = cmd->tokens;
		while (tokens)
		{
			tokens->t_idx = index;
			index++;
			tokens = tokens->next;
		}
		index = 0;
		cmd = cmd->next;
	}
}
