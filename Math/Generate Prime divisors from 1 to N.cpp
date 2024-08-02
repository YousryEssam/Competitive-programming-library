#include<bits/stdc++.h>
using namespace std;
#define ll long long
///////////////////////////////////////////////////////////////////
// Generates all the prime divisors of the numbers from 1 to n.
vector<int> primeDivs[1000000];
void generatePrimeDivisors(int n) {
	for (int i = 2; i <= n; ++i) {
		if (primeDivs[i].size()) continue;

		for (int j = i; j <= n; j += i) {
			primeDivs[j].push_back(i);
		}
	}
}