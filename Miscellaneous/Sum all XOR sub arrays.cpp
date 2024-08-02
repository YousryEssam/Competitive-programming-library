#include<bits/stdc++.h>
using namespace std;
/////////////////////////////////////////////////////

//Sum all XOR sub arrays
// find the sum of XOR operation for all subarray
long long XOR_Sum(vector<int>& arr)
{
    int siz = arr.size();
    long long sum = 0;
    long long mul = 1;
    for (int i = 0; i < 30; i++)
    {
        long long c_odd = 0;
        bool odd = 0;
        for (int j = 0; j < siz; j++)
        {
            if ((arr[j] & (1 << i)) > 0) odd = (!odd);
            if (odd) c_odd++;
        }

        for (int j = 0; j < siz; j++)
        {
            sum += (mul * c_odd);
            if ((arr[j] & (1 << i)) > 0) c_odd = (siz - j - c_odd);
        }
        mul *= 2; 	// updating the multiplier
    }
    return sum; 	// returning the sum
}
