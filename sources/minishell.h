/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:14:17 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/07 11:25:28 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>

typedef struct s_token
{
	char	*op;
	char	*str;
	char	*blank;
	char 	*exp;
	int		op_type;
	struct s_token *next;
}	t_token;

typedef struct s_syntax_err
{
	int	bool;
	int	index;
}	t_syntax_err;

char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isalnum(int c);
int		ft_isblank(char c);
t_token	*ft_lstnew(void *content, int bool);
void	ft_lstadd_back(t_token **lst, t_token *new);
void	ft_tokenizer(t_token **token, char *line);
void	parser(t_token **token, char *line);

# endif
