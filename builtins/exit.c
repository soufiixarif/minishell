/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 01:04:16 by sarif             #+#    #+#             */
/*   Updated: 2024/07/12 01:10:28 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/minishell.h"

int my_exit(t_token *node) // get the next node to exit
{
    if (!node || (node->next && node->next->token != S_QUOTE
        && node->next->token != D_QUOTE && node->next->token != TEXT))
        exit(0); // replace 0 with the last exit status
    
}

