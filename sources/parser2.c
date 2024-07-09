/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 01:14:32 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/09 10:31:06 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_op(t_token **token, char *line, int *index)
{
	int		i;
	t_token *tmp_token;

	i = *index;
	if (ft_ispipe(line[i]))
	{
		handle_pipe(line, i);
		tmp_token = ft_lstnew(get_pipe(line, &i), PIPE);
		ft_lstadd_back(token, tmp_token);
	}
	else if (ft_isin(line[i]))
	{
		handle_in(token, line, &i);
		if (i == *index)
		{
			tmp_token = ft_lstnew(get_in(line, &i), IN);
			ft_lstadd_back(token, tmp_token);	
		}
	}
	else if (ft_isout(line[i]))
	{
		handle_out(token, line, &i);
		if (i == *index)
		{
			tmp_token = ft_lstnew(get_out(line, &i), OUT);
			ft_lstadd_back(token, tmp_token);
		}
	}
	*index = i;
}

void	ft_tokenizer(t_token **token, char *line)
{
	int		i;
	t_token *tmp_token;

	i = 0;
	while (line[i])
	{
		if (ft_isstring(line[i]))
		{
			tmp_token = ft_lstnew(get_string(line, &i), TEXT);
			ft_lstadd_back(token, tmp_token);
			continue ;
		}
		else if (ft_issnglqs(line[i]))
		{
			tmp_token = ft_lstnew(get_sq(line, &i), S_QUOTE);
			ft_lstadd_back(token, tmp_token);
			continue ;
		}
		else if (ft_isdblqs(line[i]))
		{
			tmp_token = ft_lstnew(get_dq(line, &i), D_QUOTE);
			ft_lstadd_back(token, tmp_token);
			continue ;
		}
		else if (ft_isblank(line[i]))
		{
			tmp_token = ft_lstnew(get_blank(line, &i), BLANK);
			ft_lstadd_back(token, tmp_token);
			continue ;
		}
		else if (ft_isoperator(line[i]))
		{
			handle_op(token, line, &i);
			continue ;
			exit(0);
		}
		else if (ft_isexpand(line[i]))
		{
			tmp_token = ft_lstnew(get_exp(line, &i), EXP);
			ft_lstadd_back(token, tmp_token);
			continue ;
		}
		i++;
	}
}
