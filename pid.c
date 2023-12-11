#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t my_pid;

    my_pid = getpid();
    printf("My pid is %u\n", (unsigned int)my_pid);

    return 0;
}

