bool isPrime(long long  n){ // O(sqrt(N))
	for (long long  i = 2; i * i <= n; i++) if (n % i == 0) return 0;
	return (n > 1);
}
