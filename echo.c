#include <libc.h>

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	char *args[4] = {"cat", "a", "b", NULL};

	if(execve("/bin/cat",args, env) == -1)
		perror(args[0]);
}