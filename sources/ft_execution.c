#include "minishell.h"


int ft_open(t_tokens *token, int check)
{
	int fd;

	fd = -1;
	if (check == 1)
	{
		fd = open(token->node, O_RDONLY , 0644);
		if (fd == -1)
			perror(token->node);
	}
	else if (check == 2)
		fd = open(token->node, O_CREAT | O_WRONLY, 0644);
	else if (check == 3)
		fd = open(token->node, O_CREAT | O_APPEND | O_WRONLY, 0644);
	return(fd);
}

int ft_opperation(t_cmd *cmd)
{
	int fd;
	t_tokens *token;

	token = cmd->tokens;
	while(token)
	{
		if(token->type == IN)
		{
			fd = ft_open(token->next, 1);
			if(fd == -1)
				return(-1);
			cmd->input = fd;
		}
		else if(token->type == OUT)
		{
			fd = ft_open(token->next, 2);
			cmd->output = fd;
		}
		else if (token->type == APPEND)
		{
			fd = ft_open(token->next, 3);
			cmd->output = fd;
		}
		else if (token->type == HERDOC)
			cmd->input = token->fd;
		token = token->next;
	}
	return (0);
}
void execution(t_minishell *ms)
{
	t_cmd *cmd = ms->cmd;

	while(cmd)
	{
		if(ft_opperation(cmd) == -1)
		{
			cmd = cmd->next;
			continue;
		}
		cmd = cmd->next;
	}
}
