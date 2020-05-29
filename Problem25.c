#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n = 0, answer = 0;
    printf("the no. of digits to look for:");
    scanf("%d", &n);

    answer = (int)((log(10.0) * (n - 1) + (log(5.0) / 2.0))/ log(1.6180));
    printf("the position for %d digit fibonacci number is: %d", n, answer);
    return 0;
}