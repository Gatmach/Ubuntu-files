#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int c = 5;
    pid_t pid = fork();  // Create a child process
    if (pid == 0) {
        c += 5;  // Child process modifies c
    }
    else {
        pid = fork();  // Parent creates another process
        c += 10;  // Parent process modifies c
        if (pid) {
            c += 10;  // Parent process further modifies c
        }
    }
    fork();  // Create another process
    printf("%d \n", c);
    return 0;
}

