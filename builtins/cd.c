#include "../sources/minishell.h"

void    get_to_dir(t_minishell *msh, t_cmd *cmd)
{
    char *old_pdw;

    old_pdw = getcwd(NULL, 0);
    if (chdir(cmd->av[1]) == -1)
        perror(cmd->av[1]);
    else
    {
        msh->env = set_oldpwd(msh, old_pdw);
        sort_env(msh->env, ft_countline(msh->env));
    }
}

void print_oldpwd(t_minishell *msh)
{
    char *old_pwd;
    char *pwd;

    old_pwd = ft_getenv("OLDPWD",msh);
    pwd = getcwd(NULL, 0);
    if(!old_pwd[0])
    {
        printf("minishell: cd: OLDPWD not set\n");
    }
    else
    {
        if (!chdir(old_pwd))
        {
            printf("%s\n",old_pwd);
            msh->env = set_oldpwd(msh, pwd);
            sort_env(msh->env, ft_countline(msh->env));
        }
        else
            perror(old_pwd);
    }
}   

char    **set_oldpwd(t_minishell *msh, char *old_pwd)
{
    int i;
    int check;
    char **new_env;

    i = 0;
    check = 0;
    new_env = (char **)malloc(sizeof (char *) * (ft_countline(msh->env) + 2));
    while(msh->env[i])
    {
        if (!ft_strncmp("OLDPWD=",msh->env[i],7))
        {
            new_env[i] = ft_strjoin(msh, "OLDPWD=", old_pwd);
            check = 1;
        }
        else
            new_env[i] = msh->env[i];
        i++;
    }
    if (!check)
    {
        new_env[i] = ft_strjoin(msh, "OLDPWD=", old_pwd);
        i++;
    }
    new_env[i] = NULL;
    return(new_env);
}

void    cd_no_arg(t_minishell *msh, t_cmd *cmd)
{
    (void)cmd;
    char *home;
    char *old_pwd;

    home = ft_getenv("HOME",msh);
    old_pwd = getcwd(NULL, 0);
    if(!home[0])
        printf("minishell: cd: HOME not set\n");
    else
    {
        if (chdir(home) == -1)
            perror(home);
        else
        {
            msh->env = set_oldpwd(msh, old_pwd);
            sort_env(msh->env, ft_countline(msh->env));
        }
    }
}

void    ft_cd(t_minishell *msh, t_cmd *cmd)
{
    if(!cmd->av[1])
        cd_no_arg(msh, cmd);
    else if (!ft_strcmp(cmd->av[1],"-"))
        print_oldpwd(msh);
    else
        get_to_dir(msh, cmd);
}