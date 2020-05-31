// Euler discovered the remarkable quadratic formula:

// n2+n+41

// It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤39
// . However, when n=40,402+40+41=40(40+1)+41 is divisible by 41, and certainly when n=41,412+41+41

// is clearly divisible by 41.

// The incredible formula n2−79n+1601
// was discovered, which produces 80 primes for the consecutive values 0≤n≤79

// . The product of the coefficients, −79 and 1601, is −126479.

// Considering quadratics of the form:

//     n2+an+b

// , where |a|<1000 and |b|≤1000

// where |n|
// is the modulus/absolute value of n
// e.g. |11|=11 and |−4|=4

// Find the product of the coefficients, a
// and b, for the quadratic expression that produces the maximum number of 
// primes for consecutive values of n, starting with n=0.

#include <iostream>
#include <vector>
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
    int primes[400000] = {0};
    int nMax = 0, bMax = 0, aMax = 0;
    int a = 0, n = 0;
    std::vector<int> b;

    std::cout << "I was here 1" << std::endl;
    primeSieve(primes, 400000);
    std::cout << "I was here 2" << std::endl;
    b.push_back(2);
    for(unsigned i = 3; i < 1000; i += 2){
        if(primes[i])
            b.push_back(i);
    }

    std::cout << "I was here 3" << std::endl;
    for(a = -999; a < 1001; a += 2){ //a is odd unless it's two 
        for(int i = 0; i < b.size(); i++){
            int aOdd = (i == 0) ? -1 : 0; //b[0] = even so a should be even 

            for(int j = 0; j < 2; j++){
                int sign = (j == 0) ? -1 : 1;
                n = 0;

                while(primes[abs(n * n + (a + aOdd) * n + sign * b[i])])
                {
                    n++;
                }    

                //std::cout << n << std::endl;
                if(n > nMax){
                    nMax = n;
                    aMax = a;
                    bMax = sign * b[i];
                }
            }
        }
    } 

    std::cout << "n = " << nMax << "for a = " << aMax << " and b = " << bMax 
        << " and the answer is: " << aMax * bMax;

    return 0;
}