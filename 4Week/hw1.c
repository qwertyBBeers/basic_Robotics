// #과제1
#include <stdio.h>

int main(void)
{
    int n;
    int i, j = 1;

    for(i = 1; i<10; i++){
        printf("--------%d단----------\n", i);
        for(j = 1; j < 10; j++){
            n = i*j;
            printf("%d x %d = %d\n", i, j, n);
        }
    }

    return 0;
}