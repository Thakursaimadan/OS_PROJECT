#include "types.h"
#include "stat.h"
#include "user.h"
#include "thread.h"

#define NUM_THREADS 5

int arr[NUM_THREADS];

void thread_func(void *arg) {
    int index = *(int *)arg;
    printf(1, "Thread %d starting\n", index);
    // Perform some work
    arr[index] = index * 2;
    sleep(10);
    printf(1, "Thread %d exiting\n", index);
    thread_exit();
}

int main(int argc, char *argv[]) {
    int tids[NUM_THREADS];
    int args[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        args[i] = i;
        tids[i] = thread_create(thread_func, &args[i]);

        if (tids[i] < 0) {
            printf(1, "Error: thread_create failed for thread %d\n", i);
            exit();
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_join(tids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        printf(1, "arr[%d] = %d\n", i, arr[i]);
    }

    exit();
}