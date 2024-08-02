#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(arr, value) memset(arr, value, sizeof(arr))
#define lOO 0x3f3f3f3f3f3f3f3f
///////////////////////////////////////////////////////////

//DP Buliding 
string a, b;
int dp[1001][1001];
int MinCost(int i, int j){
	if (i == sz(a)) return (sz(b) - j);
	if (j == sz(b)) return (sz(a) - i);
	int& ret = dp[i][j];
	if (~ret) return ret;
	if (a[i] == b[j]) return ret = MinCost(i + 1, j + 1);
	int option1 = MinCost(i, j + 1) + 1;
	int option2 = MinCost(i + 1, j) + 1;
	int option3 = MinCost(i + 1, j + 1) + 1;
	return ret = min({ option1 , option2 , option3 });
}
int idxShift = 0; 
void Build(int i, int j){
	if (i == sz(a)){
		int len = sz(b) - j;
		for (int ii = 0; ii < len; ii++) cout << "INSERT " << i + 1 + idxShift++ << " " << b[j + ii] << endl;
		return;
	}
	if (j == sz(b)){
		int len = sz(a) - i;
		for (int ii = 0; ii < len; ii++) cout << "DELETE " << sz(b) + 1 << '\n';
		return;
	}
	if (a[i] == b[j]){
		Build(i + 1, j + 1);
		return;
	}
	int best = MinCost(i, j);
	int option1 = MinCost(i, j + 1) + 1;
	int option2 = MinCost(i + 1, j) + 1;
	int option3 = MinCost(i + 1, j + 1) + 1;
	if (best == option1){
		cout << "INSERT " << i + 1 + idxShift++ << " " << b[j] << endl;
		Build(i, j + 1);
	}
	else if (best == option2){
		cout << "DELETE " << i + idxShift-- + 1 << '\n';
		Build(i + 1, j);
	}
	else{
		cout << "REPLACE " << i + 1 + idxShift << " " << b[j] << endl;
		Build(i + 1, j + 1);
	}
}