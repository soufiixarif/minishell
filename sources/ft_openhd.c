
#include "minishell.h"

char    *ft_getfile_name(t_minishell *msh)
{
	int		name;
	char	*path;

	name = 0;
	while(name < OPEN_MAX)
	{
		path = ft_strjoin(msh, "/tmp/", ft_itoa(msh, name));
		if (access(path, F_OK) == -1)
			return(path);
		name++;
	}
	return(NULL);
}

// char    *ft_getfile_name(t_minishell *msh)
// {
// 	char	*name;
// 	char	*path;

// 	name = malloc(1);
// 	if (!name)
// 		return (perror("malloc"), NULL);
// 	path = ft_strjoin(msh, "/tmp/.tmp",ft_itoa(msh, (int)name));
// 	if (path)
// 		return (free(name), path);
// 	return(perror("malloc"), NULL);
// }

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
	t_cmd	*cmd;
	t_tokens *token;

	cmd = msh->cmd;
	store = NULL;
	while (cmd)
	{
		token = cmd->tokens;
		while (token)
		{
			if (token->type == HERDOC)
			{
				store = NULL;
				while(1)
				{
					line = readline(">");
					if (!line || !ft_strcmp(line, token->next->node))
						break ;
					// if(token->next->type == DEL)
					// 	line = ft_expainding_hd(line);
					store = ft_strjoin(msh, store, line);
					store = ft_strjoin(msh, store, "\n");
					free(line);
				}
				input = ft_split(store, '\n');
				token->fd = ft_creatfd_forhd(msh, input);
				free(store);
			}
			token = token->next;
		}
		cmd = cmd->next;
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
