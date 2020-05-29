// Largest palindrome product
   
// Problem 4
// A palindromic number reads the same both ways.
// The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

// Find the largest palindrome made from the product of two 3-digit numbers.

#include<stdio.h>
#include<stdlib.h>

int reversed(int n){
    int rev = 0;
    while(n > 0){
        rev = 10 * rev + (n % 10);
        n /= 10;
    }
    return rev;
}

int isPalindrome(int n){
    return (n == reversed(n));
}

int main(){
    int num = 0;
    int temp1 = 0, temp2 = 0, dec = 0;
    temp1 = 999;
    while(temp1 >= 100){
        if(temp1 % 11 == 0){
            temp2 = 999;
            dec = 1;
        }
        else
        {
            temp2 = 990; //highest 3 digit num divisible by 11
            dec = 11;
        }
        while(temp2 >= temp1){
            if(temp1 * temp2 < num)
                break;
            else if(isPalindrome(temp1 * temp2))   
                num = temp1 * temp2;    
                
            temp2 -= dec;
        }
        temp1 -= 1;
    }
    printf("The answer is: %d", num);
    return 0;
}