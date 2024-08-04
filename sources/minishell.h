/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:14:17 by kelmounj          #+#    #+#             */
/*   Updated: 2024/08/03 20:51:27 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h> // for PATH_MAX :D
# include <fcntl.h>
# include <stdbool.h>


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
	Q_EXP,    //10
	Q_DEL,   //11
	DEL,        //12
} t_type;

typedef struct s_command t_cmd;

typedef struct s_tokens
{
	t_cmd			*cmd;
	char			*token;
	t_type			type;
	bool			boole;
	int				t_idx;
	int				fd;
	struct s_tokens	*next;
}	t_tokens;

typedef struct s_garbage
{
	void	*node;
	struct s_garbage *next;
}	t_garbage;

typedef struct s_syntax_err
{
	bool	b;
	int		index;
}	t_syn_err;

// typedef struct s_tokens
// {
// 	t_cmd			*cmd;
// 	char			*node;
// 	t_type			type;
// 	int				t_idx;
// 	int				fd;
// 	struct s_tokens	*next;
// }	t_tokens;

typedef struct s_minishell t_minishell;

typedef struct s_command
{
	t_tokens			*tokens;
	t_minishell			*msh;
	int					input;
	int					output;
	int					c_idx;
	int					fd[2];
	bool				fd_fail;
	char				**av;
	struct s_command	*next;
} t_cmd;

typedef struct s_minishell
{
	t_tokens		*tokens;
	t_cmd			*cmd;
	t_garbage		*global;
	t_garbage		*local;
	char			**env;
	int				shlvl;
	int				fd_max;// incriment when a fd opned
	int				pipes;
	bool			env_checker;
}	t_minishell;


char		*ft_strjoin(t_minishell *minishell, char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
char		*ft_strdup(t_minishell *minishell, t_garbage **garbage, const char *s1);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(char *s1, char *s2);
char		*ft_itoa(t_minishell *minishell, int n);
char		*ft_strchr(const char *s, int c);
char		*ft_strtrim(t_minishell *minishell, char const *s1, char const *set);
char		*_sub(t_minishell *minishell, char const *s, unsigned int start, size_t len);
char 		**ft_getfullenv(t_minishell *minishell);
char		**ft_setenv(t_minishell *minishell);
char		*ft_getenv(char *var, t_minishell *minishell);
int			ft_openhd_se(t_minishell *minishell, char *line, int *i);
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
bool		is_ambiguous(char *str);
bool		sd_handler(t_minishell *msh, char *line);
void		rm_exp(t_minishell *minishell);
void		rm_blank(t_minishell *minishell);
t_tokens	*ft_lstnew(t_minishell *minishell ,void *content, t_type type);
t_garbage	*ft_garnew(t_minishell *m, void *node);
t_tokens	*ft_newtok(t_minishell *minishell, void *content, t_type type);
t_cmd		*ft_newcmd(t_minishell *minishell, void *content);
void		*ft_malloc(t_minishell *minishell ,t_garbage **garbage, size_t size);
void		ft_free(t_garbage **garbage, int boole);
void		ft_lstadd_back(t_tokens **lst, t_tokens *new);
void		ft_garadd_back(t_garbage **lst, t_garbage *new);
void		ft_addtok_back(t_tokens **lst, t_tokens *new);
void		ft_addcmd_back(t_cmd **lst, t_cmd *new);
void		ft_garclear(t_garbage **lst);
int			getlen_string(char *line, int index);
int			getlen_sq(char *line, int index);
int			getlen_dq(char *line, int index);
int			getlen_blank(char *line, int index);
int			getlen_op(char *line, int index);
int 		getlen_pipe(char *line, int index);
int			getlen_in(char *line, int index);
int			getlen_out(char *line, int index);
char 		*get_string(t_minishell *minishell, char *line, int *index);
char		*get_sq(t_minishell *minishell, char *line, int *index);
char		*get_dq(t_minishell *minishell, char *line, int *index);
char		*get_blank(t_minishell *minishell, char *line, int *index);
char		*get_op(t_minishell *minishell, char *line, int *index);
char		*get_exp(t_minishell *minishell, int *index);
char		*get_pipe(t_minishell *minishell, char *line, int *index);
char		*get_in(t_minishell *minishell, char *line, int *index);
char		*get_out(t_minishell *minishell, char *line, int *index);
char		*get_herdoc(t_minishell *minishell, char *line, int *index);
char		*get_append(t_minishell *minishell, char *line, int *index);
void		get_del(t_minishell *minishell);
bool		handle_op(t_minishell *minishell, char *line, int *index);
bool		handle_pipe(t_minishell *minishell, char *line, int index);
bool		handle_in(t_minishell *minishell, char *line, int *index);
bool		handle_out(t_minishell *minishell, char *line, int *index);
bool		handle_herdoc(t_minishell *minishell, char *line, int index);
bool		handle_append(t_minishell *minishell, char *line, int index);
bool		ft_tokenizer(t_minishell *minishell, char *line);
bool		syntax_errorb(t_minishell *minishell, char *line, int index);
bool		syntax_errora(t_minishell *minishell, char *line, int index);
void		open_heredocs(t_minishell *minishell, char *line, int n);
void		token_handler(t_minishell *minishell);
void		qexp_handler(t_minishell *minishell);
void		expainding(t_minishell *minishell);
// void		fill_tokens(t_minishell *minishell);
// void		fill_index(t_minishell *minishell);
void		fill_cmd(t_minishell *minishell);
void		token_cmd(t_minishell *minishell);
void		token_index(t_minishell *minishell);
bool		parser(t_minishell *minishell, char *line);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize); //added here by soufiix

// soufiix
// char 	**ft_getfullenv(t_minishell *minishell);
// char	*ft_strdupp(const char *s1);
// size_t	ft_strlen(const char *s);
// int		ft_strncmp(const char *s1, const char *s2, size_t n);
// char	*ft_getenv(char *var, t_minishell *minishell);
// char	*ft_strcat(char *dest, char *src);
// char **ft_setenv(t_minishell *minishell);
// char	*ft_itoa(int n);
// int    ft_openhd(char *line, int *i);
// int	ft_strcmp(char *s1, char *s2);
void		execution(t_minishell *ms);
char		**ft_split(char const *s, char c);
int			ft_atoi(const char *str);
t_tokens	*ft_getoken(t_minishell *msh, int t_idx, int c_idx);
t_cmd		*ft_getcmd(t_minishell *msh, int c_idx);
void		printfderror(char *bash, char *infile);
void    	ft_openhd(t_minishell *msh);
int			ft_creatfd_forhd(t_minishell *msh, char **input);
char		*ft_getfile_name(t_minishell *msh);
int			ft_countline(char **environ);
void		datainit(t_minishell *msh);
int			ft_lstsize(t_cmd *lst);
void		args_maker(t_minishell *msh);
void		ft_onepipe(t_cmd	*cmd);
int			getavlen(t_cmd *cmd);
int			isbuiltin(char *av);
void		execute_onecmd(t_cmd *cmd);
int			ft_openfd(t_cmd *cmd);
int			ft_in(t_tokens *token);
int			ft_out(t_tokens *token);
int			ft_append(t_tokens *token);
char		*getlinepath(char *path, char *commande, t_cmd *cmd);
char		*ft_strcpy(char *s1, char *s2);
char		*ft_strcat(char *dest, char *src);
void		put_stderr(char *s);
void		ft_multi_pipes(t_minishell *msh);
void		execute_childe(t_cmd *cmd);
void		ft_redirection(t_cmd *cmd);
void    	handel_builtins(t_minishell *msh, t_cmd *cmd);
void		ft_env(t_minishell *msh);
void		ft_exit(t_minishell *msh, t_cmd *cmd);
void    	ft_pwd(t_minishell *msh, t_cmd *cmd);
void	    ft_unset(t_minishell *msh, t_cmd *cmd);
void	    sort_env(char **env, int size);
int			check_invalid_id(char *str);
void	    ft_echo(t_minishell *msh, t_cmd *cmd);
void		print_echo(char **av, int i);
int			ft_isdigit(char c);
int			isvalid_flag(char **av);
void    	ft_cd(t_minishell *msh, t_cmd *cmd);
void		cd_no_arg(t_minishell *msh, t_cmd *cmd);
char		**set_oldpwd(t_minishell *msh, char *old_pwd);
void		print_oldpwd(t_minishell *msh);
void		get_to_dir(t_minishell *msh, t_cmd *cmd);
char		*herexp(t_minishell *minishell, char *herdoc);











#endif
