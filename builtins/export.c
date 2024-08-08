/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 05:10:05 by sarif             #+#    #+#             */
/*   Updated: 2024/08/08 05:44:16 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/minishell.h"
#include <string.h>

char	*ft_strjoin_env(t_minishell *minishell, char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	if (!s1 && !s2)
		return(NULL); 
	if (!s1)
		return (ft_strdup(minishell, &minishell->global, s2));
	if (!s2)
		return (ft_strdup(minishell,&minishell->global,s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	str = ft_malloc(minishell, &minishell->global, len + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2 && s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (s[i] != '\0' && j < len)
	{
		ptr[j] = s[i + j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

int     check_invalid_id_export(char *str)
{
    int len;
    int i;

    i = 0;
    len = ft_strlen(str);
    if(ft_isdigit(*str))
        return(0);
    while(i < len - 2)
    {
        if (!(ft_isalnum(str[i]) || str[i] == '_'))
            return(0);
        i++;
    }
    if (!((ft_isalnum(str[i]) || str[i] == '_' || str[i] == '+') && str[i + 1] == '='))
            return(0);
    return (1);
}
char *ft_get_value(char *str)
{
    int i;
    char *value;

    i = 0;
    while(str[i] && str[i] != '=')
        i++;
    value = ft_substr(str,i + 1,ft_strlen(str));
    return(value);
}

void    print_export(t_minishell *msh)
{
    char **env = msh->env;
    int i = 0;
    int j;
    while(env[i])
    {
        j = 0;
        write(1,"declare -x ",11);
        while(env[i][j] && env[i][j] != '=')
            write(1,&env[i][j++],1);
        if(env[i][j] == '=')
        {
            write(1,"=\"",2);
            j++;
            while(env[i][j])
                write(1,&env[i][j++],1);
            write(1,"\"",1);
        }
        write(1,"\n",1);
        i++;
    }
}
int ft_ispluseq(char *str)
{
    int i;

    i = 0;
    while(str[i] && str[i] != '=')
        i++;
    if(str[i - 1] == '+')
        return(1);
    else
        return(0);
}
char *ft_getvariable(char *str)
{
    size_t i;
    char *var;

    i = 0;
    while(str[i] && str[i] != '=')
        i++;
    var = ft_substr(str,0,i + 1);
    return (var);
}

char *get_var(char *str, bool plus)
{
    char **store;

    store = ft_split(str, '=');
    if (plus)
        store[0][ft_strlen(store[0]) - 1] = '\0';
    return(store[0]);
}

char **set_variable(t_minishell *msh, char *var, bool plus)
{
    int i;
    char **new_env;

    i = -1;

    printf("count line %d\n",ft_countline(msh->env));
    new_env = (char **)malloc(sizeof (char *) * (ft_countline(msh->env) + 2));
    while(msh->env[++i])
        new_env[i] = msh->env[i];
    if(!plus)
        new_env[i] = ft_strdup(msh,&msh->global,var);
    else
    {
        new_env[i] = ft_strjoin_env(msh, get_var(var,plus),"=");// to change it later
        new_env[i] = ft_strjoin_env(msh, new_env[i], ft_get_value(var));
    }
    printf("index is %d new_variable %s\n", i, new_env[i]);
    i++;
    new_env[i] = NULL;
    return(new_env);
}

void    export_var(t_minishell *msh, t_cmd *cmd, char *var)
{
    int i;
    int len;
    bool    plus;
    char *variable;
    (void)cmd;

    i = 0;
    plus = false;
    if(ft_ispluseq(var))
        plus = true;
    variable = get_var(var, plus);
    len = ft_strlen(variable);
    while(msh->env[i])
    {
        if(!strncmp(var, msh->env[i],len) && msh->env[i][len] == '=')
        {
            if(plus)
                msh->env[i] = ft_strjoin_env(msh, msh->env[i], ft_get_value(var));
            else
            {   
                msh->env[i] = ft_strjoin_env(msh, variable, "=");
                msh->env[i] = ft_strjoin_env(msh,msh->env[i], ft_get_value(var));
            }
            return ;
        }
        i++;
    }
    msh->env = set_variable(msh,var, plus);
}
void    ft_export(t_minishell *msh, t_cmd *cmd)
{
    char **store;
    int i;

    i = 1;
    store = NULL;
    if(!cmd->av[1])
        print_export(msh);
    else
    {
        while(cmd->av[i])
        {
            if(!check_invalid_id_export(ft_getvariable(cmd->av[i])))
            {   
                printf("bash: export: \'%s\': not a valid identifier\n", ft_getvariable(cmd->av[i++]));
                continue;
            }
            else
            {
                export_var(msh, cmd, cmd->av[i]);
            }
            i++;
        }
    }
}
