/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:07:03 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/21 22:37:43 by sarif            ###   ########.fr       */
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
