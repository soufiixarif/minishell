#include "minishell.h"

void	printfderror(char *bash, char *infile)
{
	write(2, bash, ft_strlen(bash));
	write(2, ": ", 2);
	write(2, infile, ft_strlen(infile));
	write(2, ": ", 2);
	write(2, "permission denied or file not found\n", 36);
}