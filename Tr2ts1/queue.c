#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "deque.h"



void joinQ(int item)
{

    insertRight(item);
}

int leaveQ()
{
    if (isEmpty())
    {
        printf("Queue is empty!!!\n");
        exit(0);
    }
    int d;
    d = removeLeft();
    return d;
}


