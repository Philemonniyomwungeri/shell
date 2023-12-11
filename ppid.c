#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t my_ppid;

    my_ppid = getppid();
    printf("My parent pid is %u\n", (unsigned int)my_ppid);

    return 0;
}

