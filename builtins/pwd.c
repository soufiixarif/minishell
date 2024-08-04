/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:24:15 by sarif             #+#    #+#             */
/*   Updated: 2024/08/03 20:46:12 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/minishell.h"

void    ft_pwd(t_minishell *msh, t_cmd *cmd)
{
    (void)msh;
    (void)cmd;
    char *path;

    path = getcwd(NULL,0);
    printf("%s\n",path);
    free(path);
    path = NULL;
}
