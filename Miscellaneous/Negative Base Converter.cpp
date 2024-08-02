#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(arr, value) memset(arr, value, sizeof(arr))
#define lOO 0x3f3f3f3f3f3f3f3f
/////////////////////////////////////////////////////////// 

// Method to convert n to base negative Base
string toNegativeBase(int n, int negBase){
    //  If n is zero then in any base it will be 0 only
    if (n == 0) return "0";
    string converted = "";
    while (n != 0){
        // Get remainder by negative base, it can be
        // negative also
        int remainder = n % negBase;
        n /= negBase;
        // if remainder is negative, add abs(base) to
        // it and add 1 to n
        if (remainder < 0){
            remainder += (-negBase);
            n += 1;
        }
        // convert remainder to string add into the result
        converted = to_string(remainder) + converted;
    }
    return converted;
}