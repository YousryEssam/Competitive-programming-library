#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(arr, value) memset(arr, value, sizeof(arr))
#define lOO 0x3f3f3f3f3f3f3f3f
///////////////////////////////////////////////////////////
// Linear Sieve
int N = 1e6 + 9;// set the size to what you need
vector<int>prime;
vector<bool>all_primes;
void linear_sieve()
{
	all_primes = vector<bool>(N, 1);
	all_primes[0] = all_primes[1] = 0;
	for (long long i = 2; i < N; i++) {
		if (all_primes[i]) prime.push_back(i);
		for (long long j = 0; j < prime.size() && i * prime[j] < N; j++) {
			all_primes[i * prime[j]] = 0;
			if (i % prime[j] == 0)break;
		}
	}
}

//Must use sieve first
//only if n <= 10^12
vector<pair<long long,int>>prime_fact;
void prime_factorization(long long n) {
	int cnt = 0;
	for (auto e : prime) {//pr primes out of liner sieve 
		if (e * e > n)break;
		if (n < prime.size() - 1 && all_primes[n])break;
		cnt = 0;
		while (n % e == 0) {
			cnt++;
			n /= e;
		}
		if (cnt) prime_fact.push_back({ e,cnt });
	}
	if (n > 1) prime_fact.push_back({ n,1 });
}