#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

pid_t ppid;

void child();
void parent();

// Function to get the child exit status
int get_child_exit_status(pid_t child_pid)
{
    int status;
    // Wait for the child to finish and get the status code
    waitpid(child_pid, &status, 0);
    
    // Check if the child terminated normally
    if (WIFEXITED(status)) {
        return WEXITSTATUS(status);
    } else {
        return -1; // Indicate abnormal termination
    }
}

int main(void)
{  
    ppid = getpid();

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        child();
        exit(0);
    } else {
        int exit_status = get_child_exit_status(pid);
        printf("Child exited with status=%d\n", exit_status);
    }

    return 0;
}

// DO NOT MODIFY CODE BELOW
void child()
{
    pid_t c_pid = getpid();
    if (c_pid == ppid)
    {
        printf("This is not a child\n");
        return;
    }
    printf("This is a child\n");
    int status;
    scanf("%d", &status);
    exit(status);
}