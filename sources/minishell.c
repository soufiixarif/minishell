/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:07:03 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/07 14:29:51 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main()
{
	t_token	*token;
	char	*line;
	
	token = NULL;
	while (1)
	{
		line = readline("Minishell$ ");
		add_history(line);
		parser(&token, line);
		while(token)
		{
			printf("string ==> %s\n", token->str);
			printf("blank ==> %s\n", token->blank);
			printf("operator ==> %s\n", token->op);
			token = token->next;
		}
		free(line);
	}
}
