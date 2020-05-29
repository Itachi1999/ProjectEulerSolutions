#include<stdio.h>

// int main(){
//     long long int num = 600851475143;
//     long long int i = 5, max = 0;
//     while(i * i <= num){
//         if(num % i == 0 ){
//             if(i > max)   
//             {    max = i;
//                 printf("%d\n", max);} 
//         }
//         else if(num % (i + 2) == 0){
//             if((i + 2) > max){
//                 max = i + 2;
//                 printf("%d\n", max);
//             }
//         }
//         i += 6;
//     }
//     printf("the answer is: %d", max);
//     return 0;
// }

int main(){
    long long int num = 720 ; //600851475143;
    long long int i = 2;
    while(i * i < num){
        while(num % i ==0)  
            num = num / i;
        i += 1;
    }
    printf("The answer is: %d, %d", num, i);
    return 0;
}