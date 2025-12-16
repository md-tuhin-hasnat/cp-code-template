#include<bits/stdc++.h>
using namespace std;

/// divisor pre calculate
///nlog(log(n))
vector<int>divisors[1000010];
void Divisor()
{
    for(int div=1;div<=1000000;div++)
        for(int num=div;num<=1000000;num+=div)///num is a number 
            divisors[num].push_back(div);     //which is contain divisor div
}
