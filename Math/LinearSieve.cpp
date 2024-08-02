#include<bits/stdc++.h>
using namespace std;
#define ll long long
///////////////////////////////////////////////////////////////////
// Linear Sieve
int N = 1e6 + 9;// set the size to what you need
vector<int>prime;
vector<bool>all_primes;
void linear_sieve(){
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