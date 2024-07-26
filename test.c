#include <libc.h>
int main(int ac, char **env)
{
    char *str = "/bin/kouki";
    char *cmd[3] = {"kouki","-a",NULL};
    if(execve(str, cmd, env) == -1)
        perror(str);

}