#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(arr, value) memset(arr, value, sizeof(arr))
#define lOO 0x3f3f3f3f3f3f3f3f
///////////////////////////////////////////////////////////


struct DSU{
	vector<int>parent, GroupSize;
	DSU(int n){
		parent = GroupSize = vector<int>(n + 1);
		for (int i = 0; i <= n; i++){
			parent[i] = i;
			GroupSize[i] = 1;
		}
	}
	int FirstSearch(int i){
		if (parent[i] == i)return i;
		return parent[i] = FirstSearch(parent[i]);
	}
	int  MergeGroups(int i, int j){
		int Leader1 = FirstSearch(i), Leader2 = FirstSearch(j);
		if (Leader1 == Leader2) return 0;
		//Merge By GroupSize,There are other Ways to Merge By
		if (GroupSize[Leader1] < GroupSize[Leader2]) swap(Leader1, Leader2);
		parent[Leader2] = Leader1;
		GroupSize[Leader1] += GroupSize[Leader2];
		return 1;
	}
};

//////////////////
for(int i=d.FirstSearch(l);i<=r;i=d.FirstSearch(i))
{
    v[i]=hi;
    d.parent[i]=i+1;
}