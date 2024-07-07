/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:14:17 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/07 17:11:37 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_token
{
	char	*op;
	char	*str;
	char	*blank;
	char 	*exp;
	int		op_type;
	struct s_token *next;
}	t_token;

typedef struct s_garbage
{
	void	*node;
	struct s_garbage *next;
}	t_garbage;

typedef struct s_syntax_err
{
	int	bool;
	int	index;
}	t_syntax_err;

char		*ft_strjoin(char const *s1, char const *s2);
int			ft_isalnum(int c);
int			ft_isblank(char c);
t_token		*ft_lstnew(void *content, int bool);
t_garbage	*ft_garnew(t_garbage **garbage, void *content);
void		ft_free(t_garbage **garbage, int boole);
void		ft_lstadd_back(t_token **lst, t_token *new);
void		ft_garadd_back(t_garbage **lst, t_garbage *new);
void		ft_garclear(t_garbage **lst);
void		ft_tokenizer(t_token **token, char *line);
void		parser(t_token **token, char *line);

# endif
