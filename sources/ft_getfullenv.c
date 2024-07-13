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
char **ft_getfullenv()
{
    extern char **environ;
    char        **env;
    int         i;

    i = 0;
    // if(!env || !*env)
    //     ft_setenv();
    env = (char **)malloc(sizeof (char *) * ft_countline(environ));
    while (environ[i])
    {
        env[i] = ft_strdup(environ[i]);
        i++;
    }
    env[i] = NULL;
    return(env);
}