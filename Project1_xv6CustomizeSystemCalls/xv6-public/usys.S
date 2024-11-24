#include "syscall.h"
#include "traps.h"

#define SYSCALL(name) \
  .globl name; \
  name: \
    movl $SYS_ ## name, %eax; \
    int $T_SYSCALL; \
    ret

SYSCALL(fork)
SYSCALL(exit)
SYSCALL(wait)
SYSCALL(pipe)
SYSCALL(read)
SYSCALL(write)
SYSCALL(close)
SYSCALL(kill)
SYSCALL(exec)
SYSCALL(open)
SYSCALL(mknod)
SYSCALL(unlink)
SYSCALL(fstat)
SYSCALL(link)
SYSCALL(mkdir)
SYSCALL(chdir)
SYSCALL(dup)
SYSCALL(getpid)
SYSCALL(sbrk)
SYSCALL(sleep)
SYSCALL(uptime)
SYSCALL(getyear)
SYSCALL(msgsend)
SYSCALL(msgrecv)
SYSCALL(sigstop)
SYSCALL(sigcont)
SYSCALL(clone)
SYSCALL(join)


// usys.S
.globl mutex_lock
.globl mutex_unlock

mutex_lock:
    movl $SYS_mutex_lock, %eax
    int $64
    ret

mutex_unlock:
    movl $SYS_mutex_unlock, %eax
    int $64
    ret
