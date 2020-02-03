#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void)
{
    int i,s;

    for (i = 0; i < 10; i++)
    {
        joinQ(i * i);
        s=size();
        printf("size= %d  Data = %d\n",s, leaveQ());
        joinQ(i * i * i);
    }
    while (!isEmpty())
    {
        printf("Emptying queue %d\n", leaveQ());
    }
    return 0;
}
