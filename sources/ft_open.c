/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:52:29 by sarif             #+#    #+#             */
/*   Updated: 2024/07/16 16:21:07 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>

static t_tokens *create_token(const char *node, t_type type) {
    t_tokens *new_token = malloc(sizeof(t_token));
    new_token->node = strdup(node);
    new_token->type = type;
    new_token->next = NULL;
    return new_token;
}

static t_cmd *create_cmd() {
    t_cmd *new_cmd = malloc(sizeof(t_cmd));
    new_cmd->tokens = NULL;
    new_cmd->next = NULL;
    return new_cmd;
}

static void datainit(t_minishell *msh) {
    t_cmd *cmd1 = create_cmd();
    t_cmd *cmd2 = create_cmd();
    t_cmd *cmd3 = create_cmd();

    msh->cmd = cmd1;
    cmd1->next = cmd2;
    cmd2->next = cmd3;

    // Initialize tokens for cmd1
    cmd1->tokens = create_token("ls -la", TEXT);
    cmd1->tokens->next = create_token(">", OUT);
    cmd1->tokens->next->next = create_token("f1", TEXT);

    // Initialize tokens for cmd2
    cmd2->tokens = create_token("cat", TEXT);
    cmd2->tokens->next = create_token("<<", HERDOC);
    cmd2->tokens->next->next = create_token("lim1", DEL);
    cmd2->tokens->next->next->next = create_token("<<", HERDOC);
    cmd2->tokens->next->next->next->next = create_token("lim2", DEL);

    // Initialize tokens for cmd3
    cmd3->tokens = create_token("grep a", TEXT);
    cmd3->tokens->next = create_token("<<", HERDOC);
    cmd3->tokens->next->next = create_token("lim3", DEL);
    cmd3->tokens->next->next->next = create_token(">", OUT);
    cmd3->tokens->next->next->next->next = create_token("f2", TEXT);

    // Print the commands and tokens
    t_cmd *cmd = msh->cmd;
    while (cmd) 
    {
        t_tokens *token = cmd->tokens;
        while (token) {
            printf("token: %s\n", token->node);
            printf("type: %u\n", token->type);
            token = token->next;
        }
        cmd = cmd->next;
    }
}

// void ft_in(t_minishell *msh)// need index
// {
    
// }

void    ft_open(t_minishell *msh)
{
    datainit(msh);
    // while(msh->cmd)
    // {
    //     while(msh->cmd->tokens)
    //     {
    //         if(ft_strcmp(msh->cmd->tokens->typee, "<"))
    //             ft_in(msh);
    //         else if(!ft_strcmp(msh->cmd->tokens->typee, ">"))
    //             ft_out(msh);
    //         else if(!ft_strcmp(msh->cmd->tokens->typee, ">>"))
    //             ft_heredoc(msh);
    //         else if (!ft_strcmp(msh->cmd->tokens->typee, ">>"))
    //             ft_append(msh);
    //         msh->cmd->tokens = msh->cmd->tokens->next;
    //     }
    //     msh->cmd = msh->cmd->next;
    // }
    
}