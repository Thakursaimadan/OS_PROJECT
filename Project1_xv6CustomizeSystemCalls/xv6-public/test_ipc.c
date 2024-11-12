// test_ipc.c
#include "types.h"
#include "stat.h"
#include "user.h"

#define MAX_MSG_SIZE 128  // Make sure this matches the kernel definition

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf(2, "Usage: test_ipc message\n");
        exit();
    }

    int pid = fork();
    if(pid < 0) {
        printf(2, "Fork failed\n");
        exit();
    }

    if(pid == 0) {  // Child process
        printf(1, "Child process started with pid %d\n", getpid());
        char buf[MAX_MSG_SIZE];
        sleep(500);  // Wait for parent to send
        printf(1, "Child trying to receive message...\n");
        if(msgrecv(getpid(), buf) < 0) {
            printf(2, "No message received by child\n");
        } else {
            printf(1, "Child received message: %s\n", buf);
        }
    } else {  // Parent process
        printf(1, "Parent trying to send message to child pid %d\n", pid);
        sleep(10);  // Give child time to start
        if(msgsend(pid, argv[1]) < 0) {
            printf(2, "Failed to send message\n");
        } else {
            printf(1, "Message sent to child\n");
        }
        wait();
    }
    exit();
}
