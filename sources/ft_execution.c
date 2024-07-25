/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:08:44 by sarif             #+#    #+#             */
/*   Updated: 2024/07/25 17:18:40 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>
int	isbuiltin(char *av)
{
	char **builtin = {"echo","cd","pwd","export","unset","env", "exit",NULL};
	int i = 0;

	while(builtin[i])
	{
		if (!ft_strcmp(av, builtin[i]))
			return(1);
		i++;
	}
	return(0);
}
int	getavlen(t_cmd *cmd)
{
	int 		counter;
	t_tokens	*token;

	counter = 0;
	token = cmd->tokens;
	while(token)
	{
		if(token->type != TEXT)
			token = token->next;
		else
			counter++;
		token = token->next;
	}
	return(counter + 1);
}
void	args_maker(t_minishell *msh)
{
	t_tokens *token;
	t_cmd	*commande;
	int		i;

	commande = msh->cmd;
	while(commande)
	{
		commande->av = (char**)malloc(sizeof(char *) * getavlen(commande));
		token = commande->tokens;
		i = 0;
		while (token)
		{
			if (token->type != TEXT)
				token = token->next;
			else
				commande->av[i++] = strdup(token->node);
			token = token->next;
		}
		commande->av[i] = NULL;
		commande = commande->next;
	}
}
void ft_onepipe(t_cmd	*cmd)
{
	
	if (isbuiltin(cmd->av[0]));
		// noforkbuilting(av);//TO DO
	else if (!isbuiltin(cmd->av[0]))
		
}
void execution(t_minishell *ms)
{
	t_cmd *commande;

	commande = ms->cmd;
	args_maker(ms);
	ms->pipes = ft_lstsize(ms->cmd);
	if (ms->pipes == 1)
		ft_onepipe(ms->cmd);
}
