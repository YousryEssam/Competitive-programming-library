#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define lOO 0x3f3f3f3f3f3f3f3f
///////////////////////////////////////////////////////////

//Knapsack 2
const int N = 102, Val = 1e5 + 2;
int w[N], v[N], n, W;
ll Dp[N][Val], INF = 1e14;
ll Knapsack2(int i, int val) {
	if (i >= n) return val == 0 ? 0 : INF;
	ll& ret = Dp[i][val];
	if (~ret) return ret;
	ret = Knapsack2(i + 1, val);
	if (val >= v[i])
		return ret = min(Knapsack2(i + 1, val), Knapsack2(i + 1, val - v[i]) + w[i]);
	return ret;
}