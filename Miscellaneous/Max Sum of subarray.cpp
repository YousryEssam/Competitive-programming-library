#include<bits/stdc++.h>
using namespace std;
///////////////////////////////////////////////////////////////////

// max sum of consecutive elements 
long long maxSubArrySum(vector<long long>& v) {
	int n = v.size();
	long long  l = 0, r = 0, sum = 0, mx = 0;
	for (int i = 0, j = 0; i < n ; i++){
		sum += v[i];
		if (sum < 0) sum = 0, j = i + 1;
		if (sum > mx || sum == mx && i - j > r - l){
			mx = sum;
			r = i + 2;
			l = j + 1;
		}
	}
	return mx;
}