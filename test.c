#include <stdio.h>
#include <string.h>

// Function to sort environment variables and move NULLs to the bottom
void sort_env(char **env, int size) {
    int i, j;
    char *temp;

    i = 0;
    while (i < size - 1) {
        j = 0;
        while (j < size - 1) {
            if (env[j] == NULL) {
                // Swap NULL to the bottom
                temp = env[j];
                env[j] = env[j + 1];
                env[j + 1] = temp;
            } else if (env[j + 1] != NULL && strcmp(env[j], env[j + 1]) > 0) {
                // Swap if the current string is greater than the next (alphabetical order)
                temp = env[j];
                env[j] = env[j + 1];
                env[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

int main() {
    char *env[] = {
        "MallocNanoZone=0",
        "USER=mac",
        "COMMAND_MODE=unix2003",
        "LOGNAME=mac",
        NULL, // Let's say USER was unset and replaced by NULL
        "PATH=/usr/local/bin:/usr/bin:/bin",
        "HOME=/Users/mac",
        "SHELL=/bin/zsh",
        "TMPDIR=/var/folders/dr/cmhbxvn96hlgcxwr0mmc656c0000gn/T/",
        "PWD=/Users/mac/Desktop/minishell",
        "OLDPWD=/Users/mac/Desktop",
        NULL // Terminator (end of array)
    };

    // Determine the size of the environment array
    int size = 0;
    while (env[size] != NULL || env[size + 1] != NULL) {
        size++;
    }

    // Sort the environment variables and move NULLs to the bottom
    sort_env(env, size);

    // Print the sorted environment variables
    int i = 0;
    while (i < size) {
        if (env[i] != NULL) {
            printf("%s\n", env[i]);
        }
        i++;
    }

    return 0;
}