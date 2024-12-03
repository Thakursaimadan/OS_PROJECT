int thread_create(void (*function)(void*), void *arg);
int thread_join(int tid);
void thread_exit(void) __attribute__((noreturn));