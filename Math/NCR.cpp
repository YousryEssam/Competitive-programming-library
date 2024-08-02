#include<bits/stdc++.h>
using namespace std;
///////////////////////////////////////////////////////////////////
unsigned long long NCR(int n, int r)
{
	if (r > n) return 0;
	r = max(r, n - r); //nCr(n,r) = nCr(n,n-r)
	unsigned long long ans = 1, div = 1, i = r + 1;
	while (i <= n) {
		ans *= i;
		i++;
		ans /= div;
		div++;
	}
	return ans;
}