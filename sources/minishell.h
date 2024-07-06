/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:14:17 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/06 15:19:42 by kelmounj         ###   ########.fr       */
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
	char	blank;
	struct s_token *next;
}	t_token;

typedef struct s_syntax_err
{
	int	bool;
	int	index;
}	t_syntax_err;

char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isalnum(int c);
// int		s_quote(char *line);
void	parser(char *line);

# endif
