#include<bits/stdc++.h>
using namespace std;
///////////////////////////////////////////////////////////////////

// sparse table
int n, logSize = 0;
vector<int>arr, bin_log;
vector<vector<int>>table;// m[i][j] is minimum among a[i..i+2^j-1]
const int MAX_N = 100'005;
const int LOG = 17;
int query(int L, int R) { // O(1)
    int length = R - L + 1;
    int k = bin_log[length];
	return min(table[L][k], table[R - (1 << k) + 1][k]);
}
void intiSparseTable() {
	cin >> n;
	while ((1<<logSize) <= n) logSize++;
	arr.resize(n + 10);
	bin_log.resize(n + 10);
	table.resize(n + 10, vector<int>(logSize));
	bin_log[1] = 0;
	for (int i = 2; i <= n; i++) bin_log[i] = bin_log[i / 2] + 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		table[i][0] = arr[i];
	}
	// 2) preprocessing, O(N*log(N))
	for (int k = 1; k < logSize; k++) {
		for (int i = 0; i + (1 << k) - 1 < n; i++) {
			table[i][k] = min(table[i][k - 1], table[i + (1 << (k - 1))][k - 1]);
		}
	}
}