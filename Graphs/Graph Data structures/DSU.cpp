#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define lOO 0x3f3f3f3f3f3f3f3f
///////////////////////////////////////////////////////////
//DSU 
int n, m;
// to get parent of the node
vector<int>parent, siz;
int getparent(int u){
	if (parent[u] == u) return u;
	return parent[u] = getparent(parent[u]);
}
//to join two setes and make them belongs to same parent by the size of parent 
void join(int a, int b){
	a = getparent(parent[a]);
	b = getparent(parent[b]);
	if (a != b){
		parent[a] = b;
		siz[b] += siz[a];
	}
}
