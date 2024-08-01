/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:04:10 by sarif             #+#    #+#             */
/*   Updated: 2024/07/31 22:43:03 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/minishell.h"

void    handel_builtins(t_minishell *msh, t_cmd *cmd)
{
    if(!ft_strcmp(cmd->av[0],"env"))
        ft_env(msh);
    if(!ft_strcmp(cmd->av[0],"exit"))
        ft_exit(msh, cmd);
    if(!ft_strcmp(cmd->av[0],"pwd"))
        ft_pwd(msh, cmd);
    if(!ft_strcmp(cmd->av[0],"unset"))
        ft_unset(msh, cmd);
    if(!ft_strcmp(cmd->av[0],"echo"))
        ft_echo(msh, cmd);
    if(!ft_strcmp(cmd->av[0],"cd"))
        ft_cd(msh, cmd);
}
