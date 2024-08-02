long long FastPower(long long  x, long long  n, long long  mod)  // O(log(N))
{
	long long  res = 1;
	x %= mod;
	while (n)
	{
		if (n & 1)res = ((res % mod) * (x % mod)) % mod;
		x = ((x % mod) * (x % mod)) % mod;
		n >>= 1;
	}
	return res % mod;
}
//x^1 + x^2 + x^3 + x^4 + x^5 + x^6 +..x^n  
long long sumPower(long long x, long long n, long long mod)// O(log(N))
{
	if (n == 1)return x % mod;
	long long p = sumPower(x, n >> 1, mod);
	long long ans = p + (p * FastPower(x, n >> 1, mod) % mod);
	ans %= mod;
	if (n & 1)ans += FastPower(x, n, mod);
	return ans % mod;
}