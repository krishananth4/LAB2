#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("error\n");
        exit(1);
    }

    int num = atoi(argv[1]);

    if (num < 1 || num > 10000)
    {
        printf("error\n");
        exit(1);
    }

    if (sched_tickets(num) < 0)
    {
        printf("error\n");
        exit(1);
    }

    sched_statistics();
}
