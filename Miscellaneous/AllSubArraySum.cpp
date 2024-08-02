#include<vector>
using namespace std;
/////////////////////////////////////////////////////////////
// Sum of all Subarrays
// function compute sum all sub - array  O(N)
long long SubArraySum(vector<long long>&arr , long long MOD){
    int siz = arr.size(); 
    long int result = 0;
    // computing sum of subarray using formula
    for (int i = 0; i < siz; i++){
        result += (arr[i] * (i + 1) * (siz - i));
        result %= MOD;
    }
    // return all subarray sum
    return result;
}