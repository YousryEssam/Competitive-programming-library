#include<bits/stdc++.h>
using namespace std;
#define ll long long
///////////////////////////////////////////////////////////////////
// N at max 1e6 
const int N = 1e6 + 9;
vector<int> divs[N];
void generateDivisors(int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; j += i)
			divs[j].push_back(i);
	}
}