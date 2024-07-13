#include "minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	else
		return (((unsigned char)s1[i] - (unsigned char)s2[i]));
}

char	*ft_getenv(char *var, t_minishell *minishell)
{
	char	*tmp;
	int		i;

	i = 0;
	while (minishell->env[i])
	{
		tmp = ft_strdup(minishell->env[i]);
		if (ft_strncmp(var, minishell->env[i], ft_strlen(var)) == 0)
			return (tmp);
		free(tmp);
		i++;
	}
	tmp = ft_strdup("");
	return (tmp);
}