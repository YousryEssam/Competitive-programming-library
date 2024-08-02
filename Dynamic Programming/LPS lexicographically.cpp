#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(arr, value) memset(arr, value, sizeof(arr))
#define lOO 0x3f3f3f3f3f3f3f3f
///////////////////////////////////////////////////////////

//longest palindromic sub-sequence and lexicographically earliest one 
string s;
int id, mx;
int dp[1001][1001];
string dps[1001][1001];
int LPS(int i, int j){
	if (i >= j) return i == j;
	int& ret = dp[i][j];
	if (~ret) return ret;
	ret = 0;
	if (s[i] == s[j]) ret = LPS(i + 1, j - 1) + 2;
	else ret = max(LPS(i + 1, j), LPS(i, j - 1));
	return ret;
}
string bulid(int i, int j){
	if (i == j) return { s[i] };
	if (i + 1 == j){
		string x = "";
		if (s[i] == s[j]) x += s[i], x += s[i];
		else x += (min(s[i], s[j]));
		return x;
	}
	string& ret = dps[i][j];
	if (ret != "") return ret;
	ret = string(1001, 'z');
	int best = LPS(i, j);
	int ch1 = LPS(i + 1, j);
	int ch2 = LPS(i, j - 1);
	if (s[i] == s[j]) ret = min(ret, s[i] + bulid(i + 1, j - 1) + s[j]);
	if (best == ch1) ret = min(ret, bulid(i + 1, j));
	if (best == ch2) ret = min(ret, bulid(i, j - 1));
	return ret;
}
void solve(int T){
	while (cin >> s){
		mem(dp, -1);
		for (int i = 0; i < sz(s); i++) for (int j = 0; j < sz(s); j++) dps[i][j] = "";
		//LPS(0, sz(s) - 1);
		cout << bulid(0, sz(s) - 1) << endl;
	}
}