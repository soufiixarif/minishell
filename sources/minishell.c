/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:07:03 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/25 15:02:00 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main()
{
	t_minishell minishell;
	char	*line;

	minishell.token = NULL;
	minishell.global = NULL;
	minishell.local = NULL;
	minishell.env = ft_getfullenv(&minishell);
	while (1)
	{
		line = readline("Minishell$ ");
		if (!line)
			exit(0);
		add_history(line);
		parser(&minishell, line);
		datainit(&minishell);
		// while(minishell.cmd){
		// 	while(minishell.cmd->tokens){
		// 		printf("%s\n",minishell.cmd->tokens->node);
		// 	minishell.cmd->tokens = minishell.cmd->tokens->next;
		// 	}
		// 	minishell.cmd = minishell.cmd->next;
		// }
		ft_openhd(&minishell);
		execution(&minishell);
		while(minishell.token)
		{
			// printf("token ==> %s\n", minishell.token->token);
			// printf("token ==> %u\n", minishell.token->type);
			minishell.token = minishell.token->next;
		}
		free(line);
	}
}

  