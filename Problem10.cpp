#include <iostream>
#include <cmath>



void primeSieve(int *primes, int n = 2000001){
    //set all even numbers as false
    for (register unsigned long i = 3; i < n; i+=2)
    {
        primes[i] = 1;
    }

    //now start the sieve
    for (register unsigned long i = 3; i * i < n; i+= 2)
    {
        if (primes[i])
        {
            for (register unsigned long j = i * i; j < n; j += i)
            {
                primes[j] = 0;
            }
            
        }
        
    }
    
    //special cases 
    primes[2] = 1;
    primes[0] = 0;
    primes[1] = 0;
}

int main(){
    register unsigned long long sum  = 0;
    int primes[2000001] = {0};
    primeSieve(primes, 2000001);
    for (register unsigned long i = 3; i < 2000001; i+=2)
    {
        if (primes[i])
        {
            sum += i;
            std::cout << sum << std::endl;
        }
        
    }
    std::cout << sum + 2 << std::endl;
}