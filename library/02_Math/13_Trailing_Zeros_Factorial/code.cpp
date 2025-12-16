#include <bits/stdc++.h>
using namespace std;

int findTrailingZeros(int n)
{
    if (n < 0) // Negative Number Edge Case
        return -1;

    int count = 0;

    for (int i = 5; n / i >= 1; i *= 5)
        count += n / i;

    return count;
}
