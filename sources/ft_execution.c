/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:49:41 by sarif             #+#    #+#             */
/*   Updated: 2024/07/15 20:49:44 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void execution(t_minishell *ms, char *line)
{
    int i = 0;
    if (!ft_strcmp(line,"env"))
    {
        while (ms->env[i])
        {
            printf("%s\n",ms->env[i]);
            i++;
        }
    }
}