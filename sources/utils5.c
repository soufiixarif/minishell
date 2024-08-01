/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:22:24 by kelmounj          #+#    #+#             */
/*   Updated: 2024/08/01 11:31:52 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// t_tokens	*ft_newtok(t_minishell *minishell, void *content, t_type type)
// {
// 	t_tokens	*tokens;
// 	static int	index;

// 	index = 0;
// 	tokens = (t_tokens *)ft_malloc(minishell, &minishell->local, sizeof(t_tokens));
// 	tokens->tokens = content;
// 	tokens->type = type;
// 	tokens->next = NULL;
// 	tokens->fd = -1;
// 	tokens->t_idx = index++;
	
// 	return (tokens);
// }

// void	ft_addtok_back(t_tokens **lst, t_tokens *new)
// {
// 	t_tokens	*tmp;

// 	if (lst && new)
// 	{
// 		if (*lst)
// 		{
// 			tmp = *lst;
// 			while (tmp->next)
// 				tmp = tmp->next;
// 			(tmp)->next = new;
// 		}
// 		else 
// 			*lst = new;
// 	}
// }

t_cmd	*ft_newcmd(t_minishell *minishell, void *content)
{
	t_cmd		*cmd;

	cmd = (t_cmd *)ft_malloc(minishell, &minishell->local, sizeof(t_cmd));
	cmd->msh = minishell;
	cmd->tokens = content;
	cmd->input = 0;
	cmd->output = 1;
	cmd->fd_fail = false;
	cmd->next = NULL;
	return (cmd);
}

void	ft_addcmd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*tmp;

	if (lst && new)
	{
		if (*lst)
		{
			tmp = *lst;
			while (tmp->next)
				tmp = tmp->next;
			(tmp)->next = new;
		}
		else 
			*lst = new;
	}
}