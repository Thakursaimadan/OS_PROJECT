//user program to test get year system call
#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
	printf(1,"unix was released in the year %d\n",getyear());
	exit();
}
