/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:07:03 by kelmounj          #+#    #+#             */
/*   Updated: 2024/08/01 23:36:16 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main()
{
	t_minishell minishell;
	char	*line;

	// minishell.token = NULL;
	minishell.tokens = NULL;
	minishell.cmd = NULL;
	minishell.global = NULL;
	minishell.local = NULL;
	minishell.env = ft_getfullenv(&minishell);
	while (1)
	{
		line = readline("Minishell🍉🔻$ ");
		if (!line)
			exit(0);
		if(!line[0])
			continue;
		add_history(line);
		if (parser(&minishell, line) == true)
		{
			free(line);
			ft_free(&minishell.local, 0);
			minishell.tokens = NULL;
			continue;
		}
		// datainit(&minishell);
		// while(minishell.cmd){
		// 	while(minishell.cmd->tokens){
		// 		printf("%s\n",minishell.cmd->tokens->node);
		// 	minishell.cmd->tokens = minishell.cmd->tokens->next;
		// 	}
		// 	minishell.cmd = minishell.cmd->next;
		// }
		ft_openhd(&minishell);
		execution(&minishell);
		// while(minishell.tokens)
		// {
		// 	printf("token ==> %s\t", minishell.tokens->token);
		// 	printf("type ==> %u\t", minishell.tokens->type);
		// 	printf("index ==> %d\t", minishell.tokens->t_idx);
		// 	printf("fd ==> %d\t", minishell.tokens->fd);
		// 	printf("\n");
		// 	minishell.tokens = minishell.tokens->next;
		// }
		minishell.tokens = NULL;
		int i = 0;
		while(minishell.cmd)
		{
			printf("c_index ==> %d\n", minishell.cmd->c_idx);
			while (minishell.cmd->tokens)
			{
				printf("%d, tokens ==> %s\t",i++, minishell.cmd->tokens->token);
				printf("type ==> %u\t", minishell.cmd->tokens->type);
				printf("index ==> %d\t", minishell.cmd->tokens->t_idx);
				minishell.cmd->tokens = minishell.cmd->tokens->next;
			}
		printf("\n------------------------------------------------\n");
			minishell.cmd = minishell.cmd->next;
		}
		free(line);
	}
}
