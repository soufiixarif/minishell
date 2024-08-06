/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 05:10:05 by sarif             #+#    #+#             */
/*   Updated: 2024/08/05 06:55:08 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/minishell.h"
int     check_invalid_id_export(char *str)
{
    int len;
    int i;

    i = 0;
    len = ft_strlen(str);
    if(ft_isdigit(*str))
        return(0);
    while(i < len - 1)
    {
        if (!(ft_isalnum(str[i]) || str[i] == '_'))
            return(0);
        i++;
    }
    return (1);
}
void    update_export(t_minishell *msh, t_cmd *cmd, int i, bool plus)
{
    char *store;
    char **split;

    if(plus)
    {
        split = ft_split(cmd->av[1],'+');
        store = ft_strjoin(msh, msh->env[i], split[1] + 1);
        msh->env[i] = ft_strdup(msh, &msh->global, store);
    }
}
void    make_export(t_minishell *msh, t_cmd *cmd, bool plus, char *var)
{
    int i;
    int len;
    int update;
    // int count_line;

    i = 0;
    update = 0;
    len = ft_strlen(var);
    while(msh->env[i])
    {
        if (!ft_strncmp(var,msh->env[i],len) && msh->env[i][len] == '=')
        {
            update_export(msh, cmd, i, plus);
            update = 1;   
        }
        i++;
    }
    // if(!update)
    //     add_export(msh, cmd, plus);
}

void    print_export(t_minishell *msh)
{
    char **env = msh->env;
    char **store;
    int i = 0;
    while(env[i])
    {
        store = NULL;
        store = ft_split(env[i],'=');
        printf("declare -x %s=\"%s\"\n",store[0],store[1]);
        i++;
        free(store);
    }
}
void    ft_export(t_minishell *msh, t_cmd *cmd)
{
    char **store;

    store = NULL;
    if(!cmd->av[1])
        print_export(msh);
    else if(cmd->av[1])
    {
        store = ft_split(cmd->av[1],'=');
        if(!check_invalid_id_export(store[0]))
        {   
            printf("bash: export: \'%s\': not a valid identifier\n", store[0]);
            return; 
        }
        if(store[0][ft_strlen(store[0])] == '+')
            make_export(msh, cmd, true, store[0]);
        else
            make_export(msh, cmd, false, store[0]);
    }
}