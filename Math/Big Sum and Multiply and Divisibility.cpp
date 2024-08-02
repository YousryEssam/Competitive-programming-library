#include<bits/stdc++.h>
using namespace std;
#define ll long long
///////////////////////////////////////////////////////////////////
// Big Sum and Multiply and Divisibility
//Big SUM
string bigSum(string s, string t) {
    if (s.length() > t.length()) {
        swap(s, t);
    }
    ll len1 = s.length();
    ll len2 = t.length();
    string final = "";
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int c = 0;
    for (int i = 0; i < len1; i++) {
        int sum = ((s[i] - 48) + (t[i] - 48) + c);
        final.push_back(sum % 10 + 48);
        c = sum / 10;
    }
    for (ll i = len1; i < len2; i++) {
        int sum = ((t[i] - 48) + c);
        final.push_back(sum % 10 + 48);
        c = sum / 10;
    }
    if (c > 0)
        final.push_back(c + 48);
    reverse(final.begin(), final.end());
    return final;
}
//Big Multiply
string bigMult(string s, string t) {
    ll len1 = s.size();
    ll len2 = t.size();
    vector<int> final(len1 + len2, 0);
    int a = 0;
    int b = 0;
    for (ll i = len1 - 1; i >= 0; i--) {
        int c = 0;
        int n1 = s[i] - 48;
        b = 0;
        for (ll j = len2 - 1; j >= 0; j--) {
            int n2 = t[j] - 48;
            int sum = n1 * n2 + final[a + b] + c;
            c = sum / 10;
            final[a + b] = sum % 10;
            b++;
        }
        if (c > 0)
            final[a + b] += c;
        a++;
    }
    ll rem = final.size() - 1;
    while (rem >= 0 && final[rem] == 0) {
        rem--;
    }
    if (rem == -1)
        return "0";
    string f = "";
    while (rem >= 0) {
        f += to_string(final[rem--]);
    }
    return f;
}
// Big Divisibility by X
bool isDividable(string a, long long x){ // O(N)
	long long y = 0;
	for (int i = 0; i < a.size(); i++) y = (y * 10 + a[i] - '0') % x;
	return(!y);
}