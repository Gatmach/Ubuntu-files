#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *args[] = {"/bin/ls", "-l", NULL};   // Arguments for execv and execve
    char *env[] = {"MY_ENV_VAR=123", NULL};   // Environment for execle and execve

    printf("1. Demonstrating execlp()\n");
    // execlp: Replaces the current process with the 'ls -l' command
    // execlp(path, arg0, arg1, ..., argn, NULL)
    // The first argument is the program name, the next ones are the command arguments
    execlp("/bin/ls", "ls", "-l", NULL);
    // The process image is replaced, so if execlp succeeds, this line will not run.
    perror("execlp failed");  // If execlp fails, this error will print.

    printf("2. Demonstrating execle()\n");
    // execle: Executes 'ls -l' with a custom environment
    // execle(path, arg0, arg1, ..., argn, NULL, envp)
    // The environment for the new program is passed as the last argument
    execle("/bin/ls", "ls", "-l", NULL, env);
    perror("execle failed");

    printf("3. Demonstrating execv()\n");
    // execv: Takes an array of arguments
    // execv(path, argv)
    execv("/bin/ls", args);  // args array contains command and its arguments
    perror("execv failed");

    printf("4. Demonstrating execve()\n");
    // execve: Takes an array of arguments and an array of environment variables
    // execve(path, argv, envp)
    execve("/bin/ls", args, env);  // args for arguments, env for environment
    perror("execve failed");

    return 0;
}

