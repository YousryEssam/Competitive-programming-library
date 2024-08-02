#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define lOO 0x3f3f3f3f3f3f3f3f
int  n , m ;
///////////////////////////////////////////////////////////

// SCC --> Tarjan 
int ndfn = 1, n, m;
stack<int> stk;
vector<vector<int>> adjList;//main graph
vector<vector<int>> comps; //store all SCC 
vector<int> inStack; // --> must initialize by number of nodes
vector<int> lowLink; // --> must initialize by number of nodes
vector<int> dfn; // --> must initialize by number of nodes by (-1)
vector<int> comp;// --> must initialize by number of nodes by (-1)
void tarjan(int node)
{
	lowLink[node] = dfn[node] = ndfn++, inStack[node] = 1;
	stk.push(node);
	for (auto i : adjList[node])
	{
		if (dfn[i] == -1)
		{
			tarjan(i);
			lowLink[node] = min(lowLink[node], lowLink[i]);
		}
		else if (inStack[i])
			lowLink[node] = min(lowLink[node], dfn[i]);
	}
	if (lowLink[node] == dfn[node])// cant go more 
	{
		comps.push_back(vector<int>());
		vector<int>t;
		int x = -1;
		while (x != node)
		{
			x = stk.top();
			stk.pop();
			inStack[x] = 0;
			comps.back().push_back(x);
			comp[x] = sz(comps) - 1;
		}
	}
}
void solve()
{
	cin >> n >> m;
	dfn.resize(n + 1, -1);
	comp.resize(n + 1, -1);
	adjList.resize(n + 1);
	inStack.resize(n + 1);
	lowLink.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		adjList[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
	{
		if (~dfn[i]) tarjan(i);
	}
}