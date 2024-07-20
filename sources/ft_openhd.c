
#include "minishell.h"

// char	**ft_addnl(char **input)
// {
// 	char	**line;
// 	int		len;
// 	int		i;
// 	int		j;

// 	len = ft_countline(input);
// 	i = 0;
// 	line = (char **) malloc(len + 1 * sizeof (char *));
// 	while (i < len)
// 	{
// 		line[i] = malloc(ft_strlen(input[i]) + 2 * sizeof(char *));
// 		j = -1;
// 		while(input[i][++j])
// 			line[i][j] = input[i][j];
// 		if (i != len - 1)
// 		{	
// 			line[i][j] = '\n';
// 			line[i][j + 1] = '\0';
// 		}
// 		else
// 			line[i][j] = '\0';
// 		free(input[i]);
// 		i++;
// 	}
// 	free(input);
// 	line[i] = NULL;
// 	return(line);	
// }
char    *ft_getfile_name(t_minishell *msh)
{
	char	*name;
	char	*path;

	name = malloc(1);
	if (!name)
		return (perror("malloc"), NULL);
	path = ft_strjoin(msh, "/tmp/.tmp",ft_itoa(msh, (int)name));
	if (path)
		return (free(name), path);
	return(perror("malloc"), NULL);
}

int	ft_creatfd_forhd(t_minishell *msh, char **input)
{
	int fd;
	int fdd;
	int i;
	char *file_path;

	i = 0;
	file_path = ft_getfile_name(msh);
	fd = open(file_path, O_CREAT | O_WRONLY, 0777);
	if (fd == -1)
		exit(EXIT_FAILURE);
	fdd = open(file_path, O_RDONLY);
	if (fdd == -1)
		exit(EXIT_FAILURE);
	while(input && input[i])
	{
		write(fd,input[i], ft_strlen(input[i]));
		write(fd, "\n", 1);
		free(input[i]);
		i++;
	}
	free(input);
	close(fd);
	unlink(file_path);
	return (fdd);
}

void    ft_openhd(t_minishell *msh)
{
	char **input;
	char *store;
	char *line;
	int i;

	store = NULL;
	while (msh->cmd)
	{
		while (msh->cmd->tokens)
		{
			if (msh->cmd->tokens->type == HERDOC)
			{
				i = 0;
				store = NULL;
				while(1)
				{
					line = readline(">");
					if (!line || !ft_strcmp(line, msh->cmd->tokens->next->node))
						break ;
					store = ft_strjoin(msh, store, line);
					store = ft_strjoin(msh, store, "\n");
					free(line);
					i++;
				}
				input = ft_split(store, '\n');
				msh->cmd->tokens->fd = ft_creatfd_forhd(msh, input);
				free(store);
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
