#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(arr, value) memset(arr, value, sizeof(arr))
#define lOO 0x3f3f3f3f3f3f3f3f
///////////////////////////////////////////////////////////

//Hasing 
//MOD = 1e9 + 9 ,BASE = 31
//MOD = 2000000011 ,BASE = 53 ->careful of overflow
//*************
//MOD = 998634293,BASE = 953
//MOD = 986464091,BASE = 1013
ll power(ll x, ll n, ll mod){
	ll res = 1;
	x %= mod;
	while (n){
		if (n & 1)res = ((res % mod) * (x % mod)) % mod;
		x = ((x % mod) * (x % mod)) % mod;
		n >>= 1;
	}
	return res % mod;
}
struct hashing{
	ll MOD, BASE;
	vector<ll> Hash, modInv;
	hashing(string s, ll MOD, ll BASE, char first_char = 'a') :
		MOD(MOD), BASE(BASE), Hash(sz(s) + 1), modInv(sz(s) + 1) {
		modInv[0] = 1;
		ll base = 1;
		for (int i = 1; i <= sz(s); i++) {
			Hash[i] = (Hash[i - 1] + (s[i - 1] - first_char + 1) * base) % MOD;
			modInv[i] = power(base, MOD - 2, MOD);
			base = (base * BASE) % MOD;
		}
	}
	ll getHash(ll l, ll r) { //1-based
		return (1LL * (Hash[r] - Hash[l - 1] + MOD) % MOD * modInv[l]) % MOD;
	}
};