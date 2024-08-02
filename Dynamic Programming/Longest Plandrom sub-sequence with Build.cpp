#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define lOO 0x3f3f3f3f3f3f3f3f
///////////////////////////////////////////////////////////

//Building Longest Plandrom sub-sequence with
string s;
const int N = 1e3 + 2;
int Dp[N][N], Visbuild[N][N];
string Dpbuild[N][N];
vector<char>Ans;
int LPS(int i, int j) {
	if (i == j) return 1;
	if (i > j) return 0;
	int& ret = Dp[i][j];
	if (~ret) return ret;
	if (s[i] == s[j]) ret = LPS(i + 1, j - 1) + 2;
	else ret = max(LPS(i + 1, j), LPS(i, j - 1));
	return ret;
}
string buildLPS(int i, int j) {
	if (i == j) return string(1, s[i]);
	if (i > j) return "";
	if (Visbuild[i][j]) return Dpbuild[i][j];
	Visbuild[i][j] = 1;
	if (s[i] == s[j]) {
		return Dpbuild[i][j] = s[i] + buildLPS(i + 1, j - 1) + s[j];
	}
	Dpbuild[i][j] = string(1, 'z' + 1);
	if (LPS(i + 1, j) == LPS(i, j)) {
		Dpbuild[i][j] = min(Dpbuild[i][j], buildLPS(i + 1, j));
	}
	if (LPS(i, j - 1) == LPS(i, j)) {
		Dpbuild[i][j] = min(Dpbuild[i][j], buildLPS(i, j - 1));
	}
	return Dpbuild[i][j];
}