/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:20:25 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/07 11:13:15 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_lstnew(void *content, int bool)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	(1) && (token->str = NULL, token->blank = NULL, token->op = NULL);
	if (bool == 1)
		token->str = content;
	if (bool == 2)
		token->blank = content;
	if (bool == 3)
		token->op = content;
	token -> next = NULL;
	return (token);
}

void	ft_lstadd_back(t_token **lst, t_token *new)
{
	t_token	*tmp;

	if (lst && new)
	{
		if (*lst)
		{
			tmp = *lst;
			while (tmp -> next)
				tmp = tmp -> next;
			(tmp)-> next = new;
		}
		else 
			*lst = new;
	}
}
