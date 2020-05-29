#include<stdio.h>
#include<stdlib.h>

int main(){
    int target = 0;
    printf("the target is:");
    scanf("%d", &target);

    printf("the answer is: %d", (target * (target + 1)) *(3 * target * target - target - 2) / 12);
    return 0;
}