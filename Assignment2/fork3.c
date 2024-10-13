#include <stdio.h>
#include <unistd.h> 

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        for(int i = 0; i < 1; i++) {
            printf("Niko Juja\n");
        }
    } else if (pid > 0) {
        sleep(1); 
        for(int i = 0; i < 1; i++) {
            printf("ICS2305 ni softlife\n");
        }
    } else{
        printf("Invalid. The fork has failed.\n");
        return 1;
    }

    return 0;
}

