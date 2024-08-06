#include "minishell.h"

int    ft_append(t_tokens *token)
{
    int fd;

    if(token->cmd->fd_fail)
        return -1;
    fd = open(token->token, O_CREAT | O_RDONLY | O_APPEND, 0644);
    if(fd == -1)
    {
        token->cmd->fd_fail = true;
        perror(token->token);
    }
    return(fd);
}

int    ft_out(t_tokens *token)
{
    int fd;

    if(token->cmd->fd_fail)
        return -1;
    fd = open(token->token, O_CREAT | O_RDWR, 0644);
    if(fd == -1)
    {
        token->cmd->fd_fail = true;
        perror(token->token);
    }
    return(fd);
}

int    ft_in(t_tokens *token)
{
    int fd;

    if(token->cmd->fd_fail)
        return -1;
    if(token->boole)
        printf("minishell: %s: ambiguous redirect", token->)
    fd = open(token->token, O_RDONLY, 0644);
    if(fd == -1)
    {
        token->cmd->fd_fail = true;
        perror(token->token);
    }
    return(fd);
}
int ft_openfd(t_cmd *cmd)
{
    t_tokens *token;

    token = cmd->tokens;
    cmd->fd_fail = false;
    while (token)
    {
        if (cmd->fd_fail)
        {
            printf("la waaalo mab9inach khdamin\n");
            break;
        }
        if (token->type == IN)
            cmd->input = ft_in(token->next);
        else if(token->type == OUT)
            cmd->output = ft_out(token->next);
        else if(token->type == APPEND)
            cmd->output = ft_append(token->next);
        else if(token->type == HERDOC)
            cmd->input = token->fd;
        token = token->next;
    }
    if (cmd->fd_fail)
        return(0);
    return(1);
}