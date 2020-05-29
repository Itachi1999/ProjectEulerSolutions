#include<stdio.h>
#include<stdlib.h>

int isPrime(int n){
    if(n <= 1)  return 0;
    else if(n < 4) return 1;

    else if(n % 2 == 0 || n % 3 == 0)   return 0;

    int i = 5;
    while(i * i <= n){
        if(n % i == 0 || n % (i + 2) == 0)  return 0;
        i+= 6;
    }
    return 1;
}

int main(){
    int check = 1, count = 0;
    int limit = 0;
    printf("The position of the prime in the number system:");
    scanf("%d", &limit);
    count++; //2 is already prime, else all is odd

    while(count < limit){
        check += 2; //all odds
        if(isPrime(check))  count++;
    }

    printf("The answer is: %d", check);
    return 0;
}