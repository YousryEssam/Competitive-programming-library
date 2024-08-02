//for !n if you want Trailing Zeros you can get it by  
long long TrailingZerosOfFactorialN(long long N) {
    long long ans = 0;
    while (N > 0)
    {
        ans += N / 5;
        N /= 5;
    }
    return ans;
}