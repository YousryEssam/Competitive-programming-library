#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define lOO 0x3f3f3f3f3f3f3f3f
///////////////////////////////////////////////////////////
//DSU (Struct)
// struct to DSU;
struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }
	// get representative component (uses path compression)
	int get(int x) {
		return e[x] < 0 ? x : e[x] = get(e[x]);
	}
	bool same_set(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) {   //union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};