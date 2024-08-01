#include "sources/minishell.h"

int main()
{
    printf("OLDPWD%s\n",getcwd(NULL, 0));
    char *path = "/usr/bin/";

    if (chdir(path) == -1)
        printf("bash: cd: %s: No such file or directory",path);
    else
        printf("%s\n",getcwd(NULL, 0));

}