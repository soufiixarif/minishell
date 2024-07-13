/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:14:17 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/13 14:11:30 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef enum e_type
{
	PIPE,       //0
	S_QUOTE, //1
	D_QUOTE, //2
	TEXT,     	//3
	EXP,         //4
	BLANK,     //5
	IN,           //6
	OUT,         //7
	APPEND,   //8
	HERDOC,   //9
	Q_HERDOC,   //10
} t_type;

typedef struct s_token
{
	char	*token;
	t_type	type;
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
}	t_syn_err;

typedef struct s_tokens
{
	char			*node;
	struct s_tokens	*next;
}	t_tokens;

typedef struct s_command
{
	t_tokens			*tokens;
	t_type				types;
	struct s_command	*next;
}	t_command;

typedef struct s_minishell
{
	t_token		*token;
	t_garbage	*global;
	t_garbage	*local;
}	t_minishell;


char		*ft_strjoin(char const *s1, char const *s2);
t_syn_err	s_quote(char *line);
t_syn_err	d_quote(char *line);
int			ft_isalnum(int c);
int			ft_isblank(char c);
int			ft_isstring(char c);
int			ft_issnglqs(char c);
int			ft_isdblqs(char c);
int			ft_isoperator(char c);
int			ft_isexpand(char c);
int			ft_ispipe(char c);
int			ft_isin(char c);
int			ft_isout(char c);
t_token		*ft_lstnew(t_minishell **minishell ,void *content, t_type type);
t_garbage	*ft_garnew(t_garbage **garbage, void *content);
void		*ft_malloc(t_garbage **garbage, size_t size);
void		ft_free(t_garbage **garbage, int boole);
void		ft_lstadd_back(t_token **lst, t_token *new);
void		ft_garadd_back(t_garbage **lst, t_garbage *new);
void		ft_garclear(t_garbage **lst);
int			getlen_string(char *line, int index);
int			getlen_sq(char *line, int index);
int			getlen_dq(char *line, int index);
int			getlen_blank(char *line, int index);
int			getlen_op(char *line, int index);
int			getlen_exp(char *line, int index);
int 		getlen_pipe(char *line, int index);
int			getlen_in(char *line, int index);
int			getlen_out(char *line, int index);
char		*get_string(char *line, int *index);
char		*get_sq(char *line, int *index);
char		*get_dq(char *line, int *index);
char		*get_blank(char *line, int *index);
char		*get_op(char *line, int *index);
char		*get_exp(char *line, int *index);
char		*get_pipe(char *line, int *index);
char		*get_in(char *line, int *index);
char		*get_out(char *line, int *index);
char		*get_herdoc(char *line, int *index);
char		*get_append(char *line, int *index);
void		handle_op(t_minishell **minishell, char *line, int *index);
void		handle_pipe(t_minishell **minishell, char *line, int index);
void		handle_in(t_minishell **minishell, char *line, int *index);
void		handle_out(t_minishell **minishell, char *line, int *index);
void		handle_herdoc(t_minishell **minishell, char *line, int index);
void		handle_append(t_minishell **minishell, char *line, int index);
void		ft_tokenizer(t_minishell **minishell, char *line);
void		syntax_errorb(t_minishell **minishell, char *line, int index);
void		syntax_errora(t_minishell **minishell, char *line, int index);
void		open_heredocs(char *line, int n);
void		parser(t_minishell *minishell, char *line);

# endif
