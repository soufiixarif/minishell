/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 22:57:18 by sarif             #+#    #+#             */
/*   Updated: 2024/08/06 15:50:02 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/minishell.h"

bool equalchr(char *str)
{
    while(*str)
    {
        if(*str == '=')
            return(true);
        str++;
    }
    return(false);
}

void    ft_env(t_minishell *msh)
{
    int i;

    i = -1;
    while(msh->env[++i])
    {
        if(!msh->env_checker && !ft_strncmp("PATH=",msh->env[i],5))
            i++;
        if(equalchr(msh->env[i]))
        {   
            printf("%s",msh->env[i]);
            printf("\n");
        }
    }
}