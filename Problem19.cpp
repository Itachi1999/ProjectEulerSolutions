#include <iostream>

int isLeapYear(int year){
    if (year % 400 == 0)
    {
        return 1;
    }
    else if (year % 4 == 0 && year % 100 != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(){
    int day = 1, year = 1900, sunday = 0;
    unsigned long  count = 0;
    int n[] = {3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3}; //the odd days for each month 

    ++year;//starting from 1901
    day = 2; //for 1901
    while (year < 2001)
    {
        for (size_t i = 0; i < 12; i++)
        {   
            count = count + ((day == 0) ? 1 : 0);
            if (isLeapYear(year))
            {
                if (i == 1)
                {
                    day = (day + n[i] + 1) % 7;
                }
                else
                {
                    day = (day + n[i]) % 7;
                }
                
            }
            
            else
            {
                day = (day + n[i]) % 7;
            }
            
        } 
        year++; 
    }
    std::cout << count << std::endl;
    return 0;
}