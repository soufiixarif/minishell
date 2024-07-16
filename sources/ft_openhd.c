/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openhd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:50:16 by sarif             #+#    #+#             */
/*   Updated: 2024/07/15 20:50:18 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    ft_openhd(t_minishell *minishell, char *line, int *i)
{
    int j;
    char *del;

    j = (*i) + 2;
    while (ft_isblank(line[j]))
            j++;
    del = get_string(minishell, line, &j);
    while (1)
    {
        line = readline(">");
		if (!line || !ft_strcmp(line, del))
		{
			free (line);
			break ;
		}
        free(line);
    }
    *i = j;
    return (*i);
}