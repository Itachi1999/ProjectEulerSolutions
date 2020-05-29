/*
Multiples of 3 and 5
Problem 1
If we list all the natural numbers below 10 that are multiples of 3 or 5, 
we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include<stdio.h>
#include<conio.h>

int target = 0;

int sumByDiv(int n){
    int p = target / n;
    return n * ((p * (p + 1)) / 2);
}

int main(){
    int answer = 0;
    printf("the target is:");
    scanf("%d", &target);
    answer = sumByDiv(5) + sumByDiv(3) - sumByDiv(15);
    printf("The answer is: %d", answer);
    return 0;
}