#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void main()
{
	char ch;    
	FILE *fp;
    fp = fopen("copiedprog.c", "r");
    assert(fp != NULL);    
    ch = fgetc(fp);
    while (!feof(fp))
    {
        printf("%c", ch);
        ch = fgetc(fp);
    }
    fclose(fp);
    printf("\n");
}
