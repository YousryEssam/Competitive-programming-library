#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(arr, value) memset(arr, value, sizeof(arr))
#define lOO 0x3f3f3f3f3f3f3f3f
///////////////////////////////////////////////////////////

// all Divisors of number sqrt(N)
vector<long long> Divisors;
void allDivisors(long long n){
	for (long long i = 1; i * i <= n; i++){
		if (n % i == 0){
			Divisors.push_back(i);
			if (n / i != i) Divisors.push_back(n / i);
		}
	}
}