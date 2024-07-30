/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:07:15 by sarif             #+#    #+#             */
/*   Updated: 2024/07/30 04:38:53 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/minishell.h"
#include <string.h>

int     isvalid_flag(char **av)
{
    int j;
    int i;

    i = 1;
    while(av[i])
    {
        if(av[i][0] == '-' && av[i][1] == 'n')
        {
            j = 1;
            while(av[i][j])
            {   
                if(av[i][j] != 'n')
                    return(i);
                j++;
            }
        }
        else
            break;
        i++;
    }
    return(i);
}
void    print_echo(char **av, int i)
{
    while(av[(i)])
    {
        printf("%s",av[i]);
        if (i != (ft_countline(av) - 1))
            printf(" ");
        (i)++;
    }
}
void    ft_echo(t_minishell *msh, t_cmd *cmd)
{
    (void)msh;
    int i;

    i = isvalid_flag(cmd->av);
    print_echo(cmd->av, i);
    if (i <= 1)
        printf("\n");
}
