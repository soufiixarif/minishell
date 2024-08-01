// #include "sources/minishell.h"

// int main()
// {
//     printf("OLDPWD%s\n",getcwd(NULL, 0));
//     char *path = "/usr/bin/";

//     if (chdir(path) == -1)
//         printf("bash: cd: %s: No such file or directory",path);
//     else
//         printf("%s\n",getcwd(NULL, 0));

//     b = 0;
//     while(str[i])
//     {
//         if (str[i] == '\"' || str[i] == '\'')
//         {
//             c = str[i];
//             if (!dschecker(str, &i , str[i]))
//             {
//                 printf("sytax error near to %c\n",c);
//             }
//         }
//         i++;
//     }
// }