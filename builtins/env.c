/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 22:57:18 by sarif             #+#    #+#             */
/*   Updated: 2024/07/30 00:55:41 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/minishell.h"

void    ft_env(t_minishell *msh)
{
    int i;

    i = -1;
    while(msh->env[++i])
    {
        if(!msh->env_checker && !ft_strncmp("PATH=",msh->env[i],5))
            i++;
        printf("%s",msh->env[i]);
        printf("\n");
    }
}