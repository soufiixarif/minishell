/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:08:44 by sarif             #+#    #+#             */
/*   Updated: 2024/07/25 01:01:38 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>
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
	return(counter);
}
void	args_maker(t_cmd *cmd)
{
	t_tokens *token;
	t_cmd	*commande;
	int		i;

	i = 0;
	commande = cmd;
	while(commande)
	{
		// commande->av = (char**)malloc(sizeof(char *) * getavlen(commande));
		token = commande->tokens;
		while (token)
		{
			printf("%p\n",token->node);
			// if (token->type != TEXT)
			// 	token = token->next;
			// else
			// 		commande->av[i++] = strdup(token->node);
			// 	i++;
			token = token->next;
		}
		// commande->av[i] = NULL;
		commande = commande->next;
	}
	// exit(0);
}
// void ft_onepipe(t_cmd	*cmd)
// {
	
// }
void execution(t_minishell *ms)
{
	t_cmd *commande;

	commande = ms->cmd;
	args_maker(commande);
	while(commande)
	{
		for(int i = 0; commande->av[i];i++)
			printf("==> %s\n",commande->av[i]);
		commande = commande->next;
	}
// 	if(ms->pipes == 1)
// 		ft_onepipe(commande);
}
