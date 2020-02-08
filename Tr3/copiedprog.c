#include <stdlib.h>
#include <stdio.h>
#define size 1000

int queue[size];
int front = -1;
int rear = -1;
int isEmpty()
{
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if ((front == 1 && rear == size - 1) || (front == rear + 1))
        return 1;
    else
        return 0;
}


void joinQ(int item)
{
    if (isFull())
    {
        printf("Queue is full.\nNo further addition possible!!!\n");
        return;
    }
    if (isEmpty())
    {
        front = rear = 0;
        queue[rear] = item;
    }
    else
    {
        rear = (rear + 1) % size;
        queue[rear] = item;
    }
    return;
}

int leaveQ()
{
    if (isEmpty())
    {
        printf("Queue is empty!!!\n");
        exit(0);
    }
    int d;
    if (front == rear)
    {
        d = queue[front];
        front = rear = -1;
    }
    else
    {
        d = queue[front];
        front = (front + 1) % size;
    }
    return d;
}
int main(int argc, char *argv[]) {
	joinQ(20);
	joinQ(200);
	joinQ(100);
	joinQ(700);
	printf("%d \n", leaveQ());
	printf("%d \n", leaveQ());
	return 0;
}

