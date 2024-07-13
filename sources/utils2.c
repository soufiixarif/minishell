/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:20:25 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/12 11:03:15 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_lstnew(t_minishell **minishell, void *content, t_type type)
{
	t_token	*token;

	token = (t_token *)ft_malloc(&(*minishell)->local ,sizeof(t_token));
	token->token = content;
	token->type = type;
	token->next = NULL;
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
