#include <stdio.h>
#include "deque.h"

int main(int argc, char *argv[]) {
	joinL(20);
	joinL(200);
	joinR(100);
	joinR(700);
	printf("%d\n", size());
	printf("%d \n", leaveR());
	printf("%d\n", size());
	printf("%d \n", leaveR());
	printf("%d\n", size());
	return 0;
}
