// sum divs of 1 ,2 ,3 , 4 ,......., x 
long long sumRangeDivisors(long long x) // O(sqrt(N))
{
	long long ans = 0, left = 1, right;
	for (; left <= x; left = right + 1)
	{
		right = x / (x / left);
		ans += (x / left) * (left + right) * (right - left + 1) / 2;
	}
	return ans;
}