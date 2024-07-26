/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:08:44 by sarif             #+#    #+#             */
/*   Updated: 2024/07/26 20:37:53 by sarif            ###   ########.fr       */
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
		return (strdup(commande));
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
	put_stderr(" : commande not found\n");
	exit(1);
	return (NULL);
}

void	execute_onecmd(t_cmd *cmd)
{
	t_cmd *commande;
	char *path;
	char *line;
	pid_t pid;

	commande = cmd;
	if(!ft_openfd(commande))
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == 0)
	{
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
	{
		(close(cmd->input)) && close(cmd->output);
		waitpid(pid, NULL, 0);
	}
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
		if(token->type != TEXT)
			token = token->next;
		else
			counter++;
		token = token->next;
	}
	return(counter + 1);
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
			if (token->type != TEXT)
				token = token->next;
			else
				commande->av[i++] = strdup(token->node);
			token = token->next;
		}
		commande->av[i] = NULL;
		commande = commande->next;
	}
}
void ft_onepipe(t_cmd	*cmd)
{
	
	if (isbuiltin(cmd->av[0]));
		// noforkbuilting(av);//TO DO
	else if (!isbuiltin(cmd->av[0]))
		execute_onecmd(cmd);
}
void execution(t_minishell *ms)
{
	t_cmd *commande;

	commande = ms->cmd;
	args_maker(ms);
	ms->pipes = ft_lstsize(commande);
	if (ms->pipes == 1)
		ft_onepipe(commande);
}
