/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:52:19 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/31 14:37:03 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/minishell.h"

void	token_handler(t_minishell *minishell)
{
	get_del(minishell);
	expainding(minishell);
	qexp_handler(minishell);
	rm_exp(minishell);
	rm_blank(minishell);
	// fill_tokens(minishell);
	fill_index(minishell);
	fill_cmd(minishell);
}

bool	syntax_errorb(t_minishell *minishell, char *line, int index)
{
	bool	b;


	if (line[index] == '\0')
		printf("minishell: syntax error near unexpected token `newline'\n");
	else
		printf("minishell: syntax error near unexpected token `%c'\n", line[index]);
	open_heredocs(minishell, line, index);
	b = true;
	//exit(258);
	return (b);
}

bool	syntax_errora(t_minishell *minishell, char *line, int index)
{
	bool	b;
	open_heredocs(minishell, line, index);
	if (line[index] == '\0')
		printf("minishell: syntax error near unexpected token `newline'\n");
	else
	printf("minishell: syntax error near unexpected token `%c'\n", line[index]);
	b = true;
	//exit(258);
	return (b);
}
