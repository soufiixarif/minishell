/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:20:25 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/07 17:10:54 by kelmounj         ###   ########.fr       */
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

t_garbage	*ft_garnew(t_garbage **all, void *content)
{
	t_garbage	*garbage;

	garbage = (t_garbage *)malloc(sizeof(t_garbage));
	if (!garbage)
		return (ft_free(all, 1), NULL);
	garbage ->node = content;
	garbage -> next = NULL;
	return (garbage);
}

void	ft_garadd_back(t_garbage **lst, t_garbage *new)
{
	t_garbage	*tmp;

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

void	ft_garclear(t_garbage **lst)
{
	t_garbage	*tmp;

	if (lst && *lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free((*lst)->node);
			free(*lst);
			*lst = tmp;
		}
	}
}
