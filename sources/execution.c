/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:09:45 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/16 15:09:46 by kelmounj         ###   ########.fr       */
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