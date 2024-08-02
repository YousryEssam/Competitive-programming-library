const int N = 1e5 + 100, mod = 1e9 + 7;
// Fact , mod inverse for i , mod inverse for i!
long long fact[N], inv[N], invfact[N]; 
void factInverse(){
	fact[0] = inv[1] = fact[1] = invfact[0] = invfact[1] = 1;
	for (long long i = 2; i < N; i++){
		fact[i] = (fact[i - 1] * i) % mod;
		inv[i] = mod - (inv[mod % i] * (mod / i) % mod);
		invfact[i] = (inv[i] * invfact[i - 1]) % mod;
	}
}
long long nCr(int n, int r){
	if (r > n) return 0;
	return (((fact[n] * invfact[r]) % mod) * invfact[n - r]) % mod;
}