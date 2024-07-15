#include "minishell.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;
	int		len;

	i = -1;
	len = ft_strlen((char *)s1);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (++i < len && s1[i])
		*(p + i) = s1[i];
	*(p + i) = 0;
	return (p);
}

static int ft_countline(char **environ)
{
    int i;

    i = 0;
    while (environ[i])
    {
        i++;
    }
    return(i);
}
char **ft_getfullenv(t_minishell *minishell)
{
    extern char **environ;
    char        **env;
    char        **lvl;
    int         i;

    i = 0;
    minishell->shlvl = 1;
    if(!environ || !*environ)
        env = ft_setenv(minishell);
    else
    {
        env = (char **)malloc(sizeof (char *) * ft_countline(environ));
        while (environ[i])
        {
            if(!ft_strncmp("SHLVL=",environ[i],6))
            {
                lvl = ft_split(environ[i],'=');
                minishell->shlvl = ft_atoi(lvl[1]) + 1;
                environ[i] = ft_strjoin("SHLVL=",ft_itoa(minishell->shlvl));
            }
            env[i] = ft_strdup(environ[i]);
            i++;
        }
        env[i] = NULL;
    }
    return(env);
}