#include<bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////
class BigInt {
private:
#define CUR (*this)
	const int BASE = 1000000000;//1e9
	vector<int> v;
public:
	BigInt(const long long& val = 0) { CUR = val; }
	BigInt(const string& val) { CUR = val; }
	int size() const {return v.size();}
	bool zero() const { return v.empty();}
	BigInt& operator =(long long val) {
		v.clear();
		while (val) {
			v.push_back(val % BASE);
			val /= BASE;
		}
		return CUR;
	}
	BigInt& operator =(const BigInt& a) {
		v = a.v;
		return CUR;
	}
	BigInt& operator=(const string& s) {
		CUR = 0;
		for (const char& ch : s) CUR = CUR * 10 + (ch - '0');
		return CUR;
	}
	/*****************************compare*****************************/
	bool operator <(const BigInt& a) const {
		if (a.size() != size())
			return size() < a.size();
		for (int i = size() - 1; i >= 0; i--) {
			if (v[i] != a.v[i])
				return v[i] < a.v[i];
		}
		return false;
	}
	/*******************************add*******************************/
	BigInt operator +(const BigInt& a) const {
		BigInt res = CUR;
		int idx = 0, carry = 0;
		while (idx < a.size() || carry) {
			if (idx < a.size()) carry += a.v[idx];
			if (idx == res.size()) res.v.push_back(0);
			res.v[idx] += carry;
			carry = res.v[idx] / BASE;
			res.v[idx] %= BASE;
			idx++;
		}
		return res;
	}
	BigInt& operator +=(const BigInt& a) {
		CUR = CUR + a;
		return CUR;
	}
		/***************************multiply****************************/
		BigInt operator *(const BigInt & a) const {
		BigInt res;
		if (CUR.zero() || a.zero())
			return res;
		res.v.resize(size() + a.size());
		for (int i = 0; i < size(); i++) {
			if (v[i] == 0)
				continue;
			long long carry = 0;
			for (int j = 0; carry || j < a.size(); j++) {
				carry += 1LL * v[i] * (j < a.size() ? a.v[j] : 0);
				while (i + j >= res.size())
					res.v.push_back(0);
				carry += res.v[i + j];
				res.v[i + j] = carry % BASE;
				carry /= BASE;
			}
		}
		while (!res.v.empty() && res.v.back() == 0) res.v.pop_back();
		return res;
	}
	BigInt& operator *=(const BigInt& a) {
		CUR = CUR * a;
		return CUR;
	}
	/*****************************Division****************************/
	BigInt& operator /=(const int& a) {
		long long carry = 0;
		for (int i = (int)v.size() - 1; i >= 0; i--) {
			long long cur = v[i] + carry * BASE;
			v[i] = cur / a;
			carry = cur % a;
		}
		while (!v.empty() && v.back() == 0) v.pop_back();
		return CUR;
	}
	/******************************print******************************/
	friend ostream& operator<<(ostream& out, const BigInt& a) {
		out << (a.zero() ? 0 : a.v.back());
		for (int i = (int)a.v.size() - 2; i >= 0; i--) out << setfill('0') << setw(9) << a.v[i];
		return out;
	}
#undef CUR
};