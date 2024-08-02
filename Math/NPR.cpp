unsigned long long NPR(int n, int r)
{
	if (r > n) return 0;
	unsigned long long p = 1, i = n - r + 1;
	while (i <= n) p *= i++;
	return p;
}