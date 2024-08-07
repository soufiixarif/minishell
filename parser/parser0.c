/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:52:19 by kelmounj          #+#    #+#             */
/*   Updated: 2024/08/07 23:02:11 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/minishell.h"

void	token_handler(t_minishell *minishell)
{
	get_del(minishell);
	expainding(minishell);
	qexp_handler(minishell);
	rm_exp(minishell);
	stick_tok(minishell);
	// while (minishell->tokens)
	// {
	// 	printf("(%s)\t", minishell->tokens->token);
	// 	printf("(%u)\n", minishell->tokens->type);
	// 	minishell->tokens = minishell->tokens->next;
	// }
	// exit(0);
	rm_blank(minishell);
	fill_cmd(minishell);
	token_cmd(minishell);
	token_index(minishell);
}

bool	syntax_errorb(t_minishell *minishell, char *line, int index)
{
	bool	b;
	int		i;

	i = index;
	if (line[index] == '\0')
		printf("minishell: syntax error near unexpected token `newline'\n");
	else
		printf("minishell: syntax error near unexpected token `%c'\n", line[i]);
	open_heredocs(minishell, line, index);
	b = true;
	//exit(258);
	return (b);
}

bool	syntax_errora(t_minishell *minishell, char *line, int index)
{
	bool	b;
	int		i;

	i = index;
	open_heredocs(minishell, line, index);
	if (line[index] == '\0')
		printf("minishell: syntax error near unexpected token `newline'\n");
	else
		printf("minishell: syntax error near unexpected token `%c'\n", line[i]);
	b = true;
	//exit(258);
	return (b);
}
