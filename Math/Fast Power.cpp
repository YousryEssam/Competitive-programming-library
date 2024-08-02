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