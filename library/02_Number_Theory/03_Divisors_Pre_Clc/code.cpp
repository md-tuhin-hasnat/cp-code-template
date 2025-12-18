///nlog(log(n))
vector<int>divisors[1000010];
void Divisor_pre_clc(){
    for(int div=1;div<=1000000;div++)
        for(int num=div;num<=1000000;num+=div)
            divisors[num].push_back(div);
}
