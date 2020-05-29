// Smallest multiple
// Problem 5
// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int power(int n, int expo){
    int temp = 1;
    while(expo > 0){
        temp *= n;
        expo--;
    }
    return temp;
}

int isPrime(int n){
    if(n <=1)
        return 0;
    else if(n <= 3)
        return 1;

    if(n % 2 == 0 || n % 3 ==0)
        return 0;
    
    int i = 5;
    while(i * i <= n){
        if(n % i == 0 || n % (i + 2) == 0)
            return 0;
        
        i += 6;
    }
    return 1;
}

int main(){
    unsigned long long int answer = 1;
    int prime[32] = {0}, expo[32] = {0};
    int index = 0, target = 20, i = 0;
    printf("The Target would be:");
    scanf("%d", &target);

    prime[0] = 2; prime[1] = 3;
    for(i = 4; i <= target; i++){
        if(isPrime(i)){
            prime[2 + index] = i;
            printf("%d ", prime[2 + index]);
            index++;
        }
    }
    prime[2 + index] = 9999;//for the ending condition of the while loop
    printf("\n");
    index = 0;
    while(prime[index] <= target){
        expo[index] = 1;
        if(prime[index] <= sqrt(target))
           expo[index] = (int)(log(target) / log(prime[index]));

        printf("%d ", expo[index]);
        answer = answer * power(prime[index], expo[index]);
        printf("%d\n", power(prime[index], expo[index]));
        index++;
    }
    printf("The answer is: %d", answer);
    return 0;
}