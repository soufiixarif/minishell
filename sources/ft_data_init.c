#include "minishell.h"
#include <string.h>

static t_tokens *create_token(const char *node, t_type type, int t_idx,t_cmd *cmd) {
    t_tokens *new_token = malloc(sizeof(t_tokens));
    new_token->node = strdup(node);
    new_token->type = type;
    new_token->t_idx = t_idx;
    new_token->fd = -1;
    new_token->next = NULL;
    new_token->cmd = cmd;
    return new_token;
}

static t_cmd *create_cmd(int c_idx, t_minishell *msh) {
    t_cmd *new_cmd = malloc(sizeof(t_cmd));
    new_cmd->tokens = NULL;
    new_cmd->c_idx = c_idx;
    new_cmd->next = NULL;
    new_cmd->input = 0;
    new_cmd->output = 1;
    new_cmd->msh = msh;
    return new_cmd;
}

void datainit(t_minishell *msh) {
    int c_idx = 0;
    int t_idx = 0;
    t_cmd *cmd1 = create_cmd(c_idx++, msh);
    // t_cmd *cmd2 = create_cmd(c_idx++);
    // t_cmd *cmd3 = create_cmd(c_idx++);

    msh->cmd = cmd1;
    // cmd1->next = cmd2;
    // cmd2->next = cmd3;

    // Initialize tokens for cmd1
    cmd1->tokens = create_token("cat", TEXT, t_idx++,cmd1);
    cmd1->tokens->next = create_token("<", IN, t_idx++,cmd1);
    cmd1->tokens->next->next = create_token("f1", TEXT, t_idx++,cmd1);
    cmd1->tokens->next->next->next = create_token("-e", TEXT, t_idx++,cmd1);
    cmd1->tokens->next->next->next->next = create_token("<", IN, t_idx++,cmd1);
    cmd1->tokens->next->next->next->next->next = create_token("Makefile", TEXT, t_idx++,cmd1);
    cmd1->tokens->next->next->next->next->next->next = create_token("<<", HERDOC, t_idx++,cmd1);
    cmd1->tokens->next->next->next->next->next->next->next = create_token("del", TEXT, t_idx++,cmd1);

    // // Initialize tokens for cmd2
    // cmd2->tokens = create_token("cat", TEXT, t_idx++);
    // cmd2->tokens->next = create_token("<<", HERDOC, t_idx++);
    // cmd2->tokens->next->next = create_token("1", DEL, t_idx++);
    // cmd2->tokens->next->next->next = create_token("<<", HERDOC, t_idx++);
    // cmd2->tokens->next->next->next->next = create_token("2", DEL, t_idx++);

    // // Initialize tokens for cmd3
    // cmd3->tokens = create_token("grep a", TEXT, t_idx++);
    // cmd3->tokens->next = create_token("<", IN, t_idx++);
    // cmd3->tokens->next->next = create_token("lim3", TEXT, t_idx++);
    // cmd3->tokens->next->next->next = create_token(">", OUT, t_idx++);
    // cmd3->tokens->next->next->next->next = create_token("f2", TEXT, t_idx++);

    // Print the commands and tokens
    // t_cmd *cmd = msh->cmd;
    // while (cmd) 
    // {
    //     printf("c_idx: %d\n",cmd->c_idx);
    //     t_tokens *token = cmd->tokens;
    //     while (token) {
    //         printf("token: %s\n", token->node);
    //         printf("type: %u\n", token->type);
    //         printf("t_idx: %d\n",token->t_idx);
    //         token = token->next;
    //     }
    //     cmd = cmd->next;
    // }
}
