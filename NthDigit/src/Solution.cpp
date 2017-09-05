#include "Solution.h"

int Solution::findNthDigit(int n)
{
    long long upper = 0;
    long long lastUpper = 0;
    long long i = 0;
    long long start = 0;
    long long quotient = 0;
    long long remainder = 0;
    long long resultPos = 0;
    long long powTmp = 0;

    if(n<=9&&n>=1)
    {
        return n;
    }
    else
    {
        start = 9;
        upper = start;
        while(n>upper)
        {
            i++;
            powTmp = pow(i);
            start = powTmp-1;
            lastUpper = upper;
            upper = upper + 9*pow(i)*(i+1);
        }
        quotient = (n-lastUpper)/(i+1);
        remainder = (n-lastUpper)%(i+1);
        if(remainder==0)
        {
            resultPos = start + quotient;
            return resultPos%10;
        }
        else
        {
            resultPos = start + quotient + 1;
            powTmp = pow(i+1-remainder);
            return (resultPos/powTmp)%10;
        }
    }
}

long long Solution::pow(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return 10*pow(n-1);
    }
}
