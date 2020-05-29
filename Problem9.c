#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int solution(int n) {
    int c = 0, a = 0, b = 0;
    for (c = (n / 3 + 1); c < n / 2; c++) {

        int sqa_b = (c * c) - (n * n) + 2 * (n * c);
        int a_b = floor(sqrt(sqa_b));

        if (a_b * a_b == sqa_b) {
            b = (n - c + a_b) / 2;
            a = n - b - c;
            return (a * b * c);
        }
    }
    return -1;
}

int main(){
    int range = 0;
    printf("The range you want for a + b + c:");
    scanf("%d", &range);

    printf("The answer is: %d", solution(range));
    return 0;
}