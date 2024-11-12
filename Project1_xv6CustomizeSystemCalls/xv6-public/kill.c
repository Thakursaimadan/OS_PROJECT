#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char *argv[]) {
    int pid = atoi(argv[1]);  // Get the process ID from command-line argument
    int sig = atoi(argv[2]);  // Get the signal number from command-line argument

    if (kill(pid, sig) < 0) {
        printf(1,"Error sending signal %d to process %d\n", sig, pid);
    } else {
        printf(1,"Signal %d sent to process %d\n", sig, pid);
    }

    exit();
}

