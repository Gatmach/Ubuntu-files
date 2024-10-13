#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main() {
    DIR *proc_dir;
    struct dirent *entry;
    char path[512]; 
    FILE *file;
    int pid, ppid, priority; 
    
    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Failed to open /proc directory");
        return 1;
    }

    while ((entry = readdir(proc_dir)) != NULL) {
        
        if (entry->d_type == DT_DIR && atoi(entry->d_name) > 0) {
        
            if (snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name) >= sizeof(path)) {
                fprintf(stderr, "Path too long for process ID %s\n", entry->d_name);
                continue; 
            }
            
            file = fopen(path, "r");

            if (file != NULL) {
                fscanf(file, "%d %*s %*c %d %*d %*d %*d %*d %*d %d", &pid, &ppid, &priority);
                printf("PID: %d, Parent PID: %d, Priority: %d\n", pid, ppid, priority);
                fclose(file);
            }
        }
    }

    closedir(proc_dir);

    return 0;
}

