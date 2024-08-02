#include<bits/stdc++.h>
using namespace std;
///////////////////////////////////////////////////////////////////
// Count Divisors
bool isPrime(long long n){
	for (long long i = 2; i * i <= n; i++) if (n % i == 0) return 0;
	return (n > 1);
}
bool isPrimeSquare(long long n){
	long long sq = round(sqrt(n));
	if (sq * sq < n) {
		sq++;
		if (sq * sq != n)return false;
	}
	return isPrime(n);
}
int countDivisors(long long n){
	// ans will contain total number of divisors
	int ans = 1;
	// Loop for counting factors of n
	for (int i = 2; 1LL * i * i * i <= n; i++){
		// Calculating power of i in n.
		int cnt = 1; // cnt is power of prime i in n.
		while (n % i == 0) {// if i is a factor of n
			n = n / i;
			cnt = cnt + 1; // incrementing power
		}
		// Calculating the number of divisors
		// If n = a^p * b^q then total divisors of n
		// are (p+1)*(q+1)
		ans = ans * cnt;
	}
	// If i is greater than cube root of n
	// First case
	if (isPrime(n)) ans = ans << 1;
	// Second case
	else if (isPrimeSquare(n)) ans = ans * 3;
	// Third case
	else if (n != 1) ans = ans << 2;
	return ans; // Total divisors
}