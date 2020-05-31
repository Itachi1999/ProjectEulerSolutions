#include <iostream>
#include <vector>
#include <cmath>

int fact(int n){
    //int factorial = 1;
    if(n == 0)
        return 1;

    else
    {
        return n * fact(n - 1);
    }
}

int main(){
    //std::cout << fact(4);

    unsigned long long remain = 999999;
    std::string number = "";
    std::vector<int> nums;
    unsigned N = 0;

    for (size_t i = 0; i < 10; i++)
    {
        nums.push_back(i);
    }
    
    N = nums.size();
    for (size_t i = 1; i <= N; i++)
    {
        int j = remain / fact(N - i);
        remain = remain % fact(N - i);
        std::cout << j << std::endl;
        number = number + std::to_string(nums[j]);
        for (auto it = nums.begin(); it != nums.end(); ++it) 
            std::cout << ' ' << *it;

        std::cout << std::endl; 
        nums.erase(nums.begin() + j);

        std::cout << "remain: " << remain <<std::endl;
    }
    
    std::cout << number<< std::endl;
}