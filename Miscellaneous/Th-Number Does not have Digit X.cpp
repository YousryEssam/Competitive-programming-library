#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(arr, value) memset(arr, value, sizeof(arr))
#define lOO 0x3f3f3f3f3f3f3f3f
///////////////////////////////////////////////////////////

// number num Th not contain digit x  
/*
    Imagine that 9 is the forbidden digit.
    In this case you can just convert your number to base-9 and you're done.
    Now, what happens when the forbidden digit is different, 
    say d? It's still a base-9 number but you have to map your digits,
    such that digits below ( < )d remain unaffected, and d and above ( >= ) 
    are mapped to the digit d + 1.
    For example, when the forbidden digit is 7 and n is 125.
    Step 1: convert to base-9: 12510 = 1489
    Step 2: map the digits. 1 → 1, 4 → 4, 8 → 9
    The solution is 149.
*/
long long number_TH_not_contain_Digit_x(long long num, int  x) {
    int digit = x;
    long long ans = 0; 
    string s;
    while (num > 0){
        int nextDigit = num % 9;
        num /= 9;
        if (nextDigit < digit) s.push_back(nextDigit + '0');
        else s.push_back(nextDigit + 1 + '0');
    }
    reverse(s.begin(), s.end());
    for (auto i : s){
        ans *= 10;
        ans += (i - '0');
    }
    return ans;
}