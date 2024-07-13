/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:07:03 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/12 20:19:26 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main()
{
	t_minishell minishell;
	char	*line;
	int i = 0;

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
		while(minishell.token)
		{
			printf("token ==> %s\n", minishell.token->token);
			printf("token ==> %u\n", minishell.token->type);
			minishell.token = minishell.token->next;
		}
		free(line);
	}
}
