#include "user.h"

int shared_counter = 0;

void
increment_counter(void)
{
    for (int i = 0; i < 10; i++) {
        mutex_lock();              // Lock
        shared_counter++;          // Critical section
        printf(1, "Counter: %d\n", shared_counter);
        mutex_unlock();            // Unlock
    }
}

int main(void)
{
    if (fork() == 0) {
        increment_counter();
        exit();
    } else {
        
        increment_counter();
    }
    wait();
    exit();
}
