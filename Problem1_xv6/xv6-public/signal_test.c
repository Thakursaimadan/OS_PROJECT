// signal_test.c
#include "types.h"
#include "user.h"
#include "signal.h"   // Assuming you defined SIGSTOP and SIGCONT here

void signal_test() {
    int pid = fork();
    if (pid < 0) {
        printf(1, "Fork failed\n");
        exit();
    } else if (pid == 0) {
        // Child process: perform a task repeatedly
        while (1) {
            printf(1, "Child process running...\n");
            sleep(50);  // Sleep for a while to make output readable
        }
    } else {
        // Parent process
        printf(1, "Parent process: sending SIGSTOP to child\n");
        sleep(100);  // Wait for child to print a few lines

        // Send SIGSTOP to child
        if (kill(pid, SIGSTOP) < 0) {
            printf(1, "Failed to send SIGSTOP\n");
        } else {
            printf(1, "SIGSTOP sent, child should stop\n");
        }
        sleep(200);  // Wait to confirm child is stopped

        // Send SIGCONT to child
        printf(1, "Parent process: sending SIGCONT to child\n");
        if (kill(pid, SIGCONT) < 0) {
            printf(1, "Failed to send SIGCONT\n");
        } else {
            printf(1, "SIGCONT sent, child should continue\n");
        }

        // Wait and then kill the child
        sleep(200);
        kill(pid, SIGKILL);  // Ensure the child terminates
    }
}

int main() {
    signal_test();
    exit();
}

