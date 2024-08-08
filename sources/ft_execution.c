/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:08:44 by sarif             #+#    #+#             */
/*   Updated: 2024/08/08 23:10:09 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>

void	put_stderr(char *s)
{
	int	fd;

	fd = 2;
	while (*s)
		(write(fd, s, 1), s++);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}

char	*getlinepath(char *path, char *commande, t_cmd *cmd)
{
	char	**envpath;
	char	*com;
	int		i;

	i = 0;
	if (ft_strchr(commande, '/') != NULL)
		return (strdup(commande));// forbiden function TO CHANGE IT LATER
	envpath = ft_split(path, ':');
	while (envpath[i])
	{
		com = NULL;
		com = ft_strjoin(cmd->msh, com, envpath[i]);
		com = ft_strjoin(cmd->msh, com, "/");
		com = ft_strjoin(cmd->msh, com, commande);
		if (access(com, F_OK) == 0)
			return (com);
		i++;
	}
	put_stderr(commande);
	put_stderr(" : command not found\n");
	exit(1);
	return (NULL);
}

int	isbuiltin(char *av)
{
	char *builtin[8] = {"echo","cd","pwd","export","unset","env", "exit",NULL};
	int i = 0;

	while(builtin[i])
	{
		if (!ft_strcmp(av, builtin[i]))
			return(1);
		i++;
	}
	return(0);
}
int	getavlen(t_cmd *cmd)
{
	int 		counter;
	t_tokens	*token;

	counter = 0;
	token = cmd->tokens;
	while(token)
	{
		if(token->next && token->type != TEXT)
			token = token->next;
		else
			counter++;
		token = token->next;
	}
	return(counter + 1);
}
void	execute_onecmd(t_cmd *cmd)
{
	t_cmd *commande;
	char *path;
	char *line;
	pid_t pid;

	commande = cmd;
	pid = fork();
	if (pid == 0)
	{
		if(!ft_openfd(commande))
			exit(EXIT_FAILURE);
		dup2(cmd->output,STDOUT_FILENO);
		dup2(cmd->input,STDIN_FILENO);
		path = ft_getenv("PATH", cmd->msh);
		line = getlinepath(path, cmd->av[0], cmd);
		if (execve(line,cmd->av,cmd->msh->env) == -1)
		{
			perror("Error: ");
			exit(EXIT_FAILURE);
		}
	}
	else
		waitpid(pid, NULL, 0);
	
}

void	args_maker(t_minishell *msh)
{
	t_tokens *token;
	t_cmd	*commande;
	int		i;

	commande = msh->cmd;
	while(commande)
	{
		commande->av = (char**)malloc(sizeof(char *) * getavlen(commande));
		token = commande->tokens;
		i = 0;
		while (token)
		{
			if (token-> next && token->type != TEXT)
				token = token->next;
			else
				commande->av[i++] = strdup(token->token);
			token = token->next;
		}
		commande->av[i] = NULL;
		commande = commande->next;
	}
}
void ft_onepipe(t_cmd	*cmd)
{
	if (isbuiltin(cmd->av[0]))
		handel_builtins(cmd->msh, cmd);//TO DO 
	else
		execute_onecmd(cmd);
}

void	ft_redirection(t_cmd *cmd)
{

	if (cmd->input == 0 && cmd->c_idx != 0)
		cmd->input = cmd->fd[0];
	if (cmd->c_idx != cmd->msh->pipes - 1 && cmd->output == 1)
		cmd->output = cmd->fd[1];
	if (cmd->input != 0)
		dup2(cmd->input,STDIN_FILENO);
	if (cmd->output != 1)
		dup2(cmd->output,STDOUT_FILENO);
	if(cmd->next)
		close(cmd->fd[1]);
	if(cmd->input != 0)
		close(cmd->input);
	if(cmd->output != 1)
		close(cmd->output);
}
void execute_childe(t_cmd *cmd)
{
	char *path;
	char *line;
	path = ft_getenv("PATH", cmd->msh);
	line = getlinepath(path, cmd->av[0], cmd);
	if (execve(line,cmd->av,cmd->msh->env) == -1)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}
}

void ft_multi_pipes(t_minishell *msh)
{
	int	i;
	int pid_Store[msh->pipes];
	int pid;
	t_cmd	*commande;
	t_cmd *tmp;

	i = -1;
	commande = msh->cmd;
	tmp = NULL;
	while(++i < msh->pipes)
	{
		pipe(commande->fd);
		pid = fork();
		if (pid == 0)
		{
			if(!ft_openfd(commande))
				exit(1); // change it later
			ft_redirection(commande);
			execute_childe(commande);
		}
		close(commande->fd[1]);
		if(tmp)
			close(tmp->fd[0]);
		if (commande->next)
			commande->next->input = commande->fd[0];
		pid_Store[i] = pid;
		tmp = commande;
		commande = commande->next;
	}
	close(tmp->fd[0]);
	i = -1;
	while (++i < msh->pipes)
	{
		waitpid(pid_Store[i],NULL,0);
	}
}

void execution(t_minishell *ms)
{
	t_cmd *commande;

	commande = ms->cmd;
	args_maker(ms);
	ms->pipes = ft_lstsize(commande);
	if (ms->pipes == 1)
		ft_onepipe(commande);
	else
		ft_multi_pipes(ms);
}
