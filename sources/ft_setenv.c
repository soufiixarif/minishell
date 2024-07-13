#include "minishell.h"

char **ft_setenv(t_minishell *minishell)
{
	char	**env;
	char	*path;

	env = (char **)malloc(sizeof (char *) * 4);
	path = getcwd(NULL,0);
	env[0] = ft_strjoin("PWD=", path);
	free(path);
	env[1] = ft_strjoin("SHLVL=",ft_itoa(minishell->shlvl));
	env[2] = ft_strdup("_=/usr/bin/env");
	env[3] = NULL;
	return(env);
}
