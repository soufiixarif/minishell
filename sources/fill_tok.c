/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tok.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:45:44 by kelmounj          #+#    #+#             */
/*   Updated: 2024/08/01 11:33:56 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rm_exp(t_minishell *minishell)
{
	t_tokens	*tmp_token;

	tmp_token = minishell->tokens;
	while (tmp_token && tmp_token->type == EXP)
		tmp_token = tmp_token->next;
	minishell->tokens = tmp_token;
	while (tmp_token)
	{
		if (tmp_token->next && tmp_token->next->type == EXP)
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

// void	add_tok0(t_minishell *minishell, t_tokens *token)
// {
// 	t_tokens	*tokens_tmp;

// 	if (token->type == TEXT)
// 	{
// 		tokens_tmp = ft_newtok(minishell, token->token, TEXT);
// 		ft_addtok_back(&minishell->tokens, tokens_tmp);
// 	}
// 	else if (token->type == S_QUOTE)
// 	{
// 		tokens_tmp = ft_newtok(minishell, token->token, S_QUOTE);
// 		ft_addtok_back(&minishell->tokens, tokens_tmp);
// 	}
// 	else if (token->type == D_QUOTE)
// 	{
// 		tokens_tmp = ft_newtok(minishell, token->token, D_QUOTE);
// 		ft_addtok_back(&minishell->tokens, tokens_tmp);
// 	}
// }

// void	add_tok1(t_minishell *minishell, t_tokens *token)
// {
// 	t_tokens	*tokens_tmp;

// 	if (token->type == IN)
// 	{
// 		tokens_tmp = ft_newtok(minishell, token->token, IN);
// 		ft_addtok_back(&minishell->tokens, tokens_tmp);
// 	}
// 	else if (token->type == OUT)
// 	{
// 		tokens_tmp = ft_newtok(minishell, token->token, OUT);
// 		ft_addtok_back(&minishell->tokens, tokens_tmp);
// 	}
// 	else if (token->type == HERDOC)
// 	{
// 		tokens_tmp = ft_newtok(minishell, token->token, HERDOC);
// 		ft_addtok_back(&minishell->tokens, tokens_tmp);
// 	}
// 	else if (token->type == APPEND)
// 	{
// 		tokens_tmp = ft_newtok(minishell, token->token, APPEND);
// 		ft_addtok_back(&minishell->tokens, tokens_tmp);
// 	}
// }
// void	add_tok2(t_minishell *minishell, t_tokens *token)
// {
// 	t_tokens	*tokens_tmp;

// 	if (token->type == Q_EXP)
// 	{
// 		tokens_tmp = ft_newtok(minishell, token->token, Q_EXP);
// 		ft_addtok_back(&minishell->tokens, tokens_tmp);
// 	}
// 	else if (token->type == Q_DEL)
// 	{
// 		tokens_tmp = ft_newtok(minishell, token->token, Q_DEL);
// 		ft_addtok_back(&minishell->tokens, tokens_tmp);
// 	}
// 	else if (token->type == DEL)
// 	{
// 		tokens_tmp = ft_newtok(minishell, token->token, DEL);
// 		ft_addtok_back(&minishell->tokens, tokens_tmp);
// 	}
// 	else if (token->type == PIPE)
// 	{
// 		tokens_tmp = ft_newtok(minishell, token->token, PIPE);
// 		ft_addtok_back(&minishell->tokens, tokens_tmp);
// 	}
// }

// void	fill_tokens(t_minishell *minishell)
// {
// 	t_tokens		*tkn_t;

// 	tkn_t = minishell->tokens;
// 	while (tkn_t->next)
// 	{
// 		if (tkn_t->type == TEXT || tkn_t->type == S_QUOTE || tkn_t->type == D_QUOTE)
// 		{
// 			add_tok0(minishell, tkn_t);
// 		}
// 		else if (tkn_t->type == IN || tkn_t->type == OUT || tkn_t->type == HERDOC || tkn_t->type == APPEND)
// 		{
// 			add_tok1(minishell, tkn_t);
// 		}
// 		else if (tkn_t->type == Q_EXP || tkn_t->type == Q_DEL || tkn_t->type == DEL || tkn_t->type == PIPE)
// 		{
// 			add_tok2(minishell, tkn_t);
// 		}
// 		tkn_t = tkn_t->next;
// 	}
// }

// void	fill_index(t_minishell *minishell)
// {
// 	t_tokens	*tmp_token;
// 	int		index;

// 	index = 0;
// 	tmp_token = minishell->tokens;
// 	while (tmp_token)
// 	{
// 		tmp_token->t_idx = index;
// 		index++;
// 		tmp_token = tmp_token->next;
// 	}
// }

// void	set_cmd(t_minishell *minishell)
// {
// 	t_token	*tmp_token;

// 	tmp_token = minishell->token;
// 	while (tmp_token)
// 	{
// 		while (tmp_token->type != PIPE)
// 		{
// 			tmp_token->cmd
// 		}
// 	}
// }

// void	get_cmd(t_minishell *minishell, t_tokens *token1, t_tokens *token2, t_cmd *cmd)
// {
// 	t_tokens	*tmp;
// 	tmp = token2;
// 	cmd = ft_newcmd(minishell, token2);
// 	ft_addcmd_back(&minishell->cmd, cmd);
// 	tmp = token1;
// 	if (token1->next->next)
// 		token1 = token1->next->next;
// 	tmp->next = NULL;
// }

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
