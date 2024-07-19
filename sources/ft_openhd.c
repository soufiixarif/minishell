/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openhd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:50:16 by sarif             #+#    #+#             */
/*   Updated: 2024/07/19 22:45:36 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_addnl(char **input)
{
	char	**line;
	int		len;
	int		i;
	int		j;

	len = ft_countline(input);
	i = 0;
	line = (char **) malloc(len + 1 * sizeof (char *));
	while (i < len)
	{
		line[i] = malloc(ft_strlen(input[i]) + 2 * sizeof(char *));
		j = -1;
		while(input[i][++j])
			line[i][j] = input[i][j];
		if (i != len - 1)
		{	
			line[i][j] = '\n';
			line[i][j + 1] = '\0';
		}
		else
			line[i][j] = '\0';
		free(input[i]);
		i++;
	}
	free(input);
	line[i] = NULL;
	return(line);	
}
char    *ft_getfile_name(t_minishell *msh)
{
	int		name;
	char	*path;

	name = 0;
	while (1)
	{
		path = ft_strjoin(msh, "/tmp/",ft_itoa(msh,name));
		if (access(path, F_OK))
			return(path);
		free(path);
		name++;
	}
	return(NULL);
}

char 	*ft_creatfd_forhd(t_minishell *msh, char **input)
{
	int fd;
	int i;
	char *file_path;

	i = 0;
	file_path = ft_getfile_name(msh);
	fd = open(file_path, O_CREAT | O_RDWR, 0777);
	if (fd == -1)
		exit(EXIT_FAILURE);
	while(input[i])
	{
		write(fd,input[i],ft_strlen(input[i]));
		i++;
	}
	free(input);
	close(fd);
	return (file_path);
}

void    ft_openhd(t_minishell *msh)
{
	char **input = NULL;
	int i;

	while (msh->cmd)
	{
		while (msh->cmd->tokens)
		{
			if (msh->cmd->tokens->type == HERDOC)
			{
				input = malloc(MAX_INPUT * sizeof(char *));
				i = 0;
				while(1)
				{
					input[i] = readline(">");
					if (!input[i] || !ft_strcmp(input[i], msh->cmd->tokens->next->node))
						break;
					i++;
				}
				input[i] = NULL;
				input = ft_addnl(input);
				msh->cmd->tokens->next->node = ft_creatfd_forhd(msh, input);
			}
			msh->cmd->tokens = msh->cmd->tokens->next;
		}
		msh->cmd = msh->cmd->next;
	}
}

int    ft_openhd_se(t_minishell *minishell, char *line, int *i)
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
