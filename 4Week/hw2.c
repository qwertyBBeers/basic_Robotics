// #과제2
#include <stdio.h>

int main(void)

{
    long fact = 1;
    int i, n;

    printf("정수를 입력하시오 : ");
    scanf("%d", &n);

    for(i = n; i>0; i--){
        fact = fact*i;
    }

    printf("%d!은 %d 입니다. \n", n, fact);

    return 0;
}