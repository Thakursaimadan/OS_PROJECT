#include "types.h"
#include "user.h"
#include "mmu.h"
#include "thread.h"

int
thread_create(void (*function)(void*), void *arg)
{
    void *stack = malloc(PGSIZE);
    if (stack == 0)
        return -1;

    // Align stack to page boundary
    if ((uint)stack % PGSIZE)
        stack = stack + (PGSIZE - (uint)stack % PGSIZE);

    int tid = clone(function, arg, stack);
    if (tid < 0)
        free(stack);

    return tid;
}

int
thread_join(int tid)
{
    void *stack;
    int ret = join(tid, &stack);
    if (ret > 0)
        free(stack);
    return ret;
}


void thread_exit(void) {
    exit();
}