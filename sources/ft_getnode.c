#include "minishell.h"

t_cmd   *ft_getcmd(t_minishell *msh, int c_idx)
{
    t_cmd *tmp_cmd = msh->cmd;

    while(tmp_cmd)
    {
        if(tmp_cmd->c_idx == c_idx)
            return(tmp_cmd);
        tmp_cmd = tmp_cmd->next;
    }
    return (NULL);
}
t_tokens *ft_getoken(t_minishell *msh, int t_idx, int c_idx)
{
    t_cmd *tmp_cmd = ft_getcmd(msh,c_idx);
    t_tokens *tmp_token = tmp_cmd->tokens;

    while(tmp_token)
    {
        if(tmp_token->t_idx == t_idx)
             return(tmp_token);
        tmp_token = tmp_token->next;
    }
    return(NULL);
}