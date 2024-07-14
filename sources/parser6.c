/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:52:19 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/14 06:12:26 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// token_handler(t_token **token)
// {
// 	t_token *tmp_token;
	
// 	tmp_token = *token;
// 	while (tmp_token)
// 	{
// 		if (tmp_token->type == TEXT)
// 		{
// 			text_handler();
// 		}
// 	}
// }

void	syntax_errorb(t_minishell **minishell, char *line, int index)
{
	printf("minishell: syntax error near unexpected token `%c'\n", line[index]);
	open_heredocs(line, index);
	ft_free(&(*minishell)->local, 0);
	//exit(258);
}

void	syntax_errora(t_minishell **minishell, char *line, int index)
{
	open_heredocs(line, index);
	printf("minishell: syntax error near unexpected token `%c'\n", line[index]);
	ft_free(&(*minishell)->local, 0);
	//exit(258);
}









































// cmd : cat Makefile -> | -> ls
// iofiles : < input1 -> > out -> << 3 -> >> app -> > s -> < input2
// fdin : 8
// fdout : 7



// cmd: < input1 cat $HOME > out >> app > s | < input2 ls

// cmd = < input1 cat "/user/.." > out >> app > "a b" | < in ls

// struct exec
// {
// 	cmd = < input1 cat "/user/.." > out >> app > "a b"
// 	fdin = 0
// 	fdout = 1
// }


// cmd = ls
// fdin = 0
// fdout = 1