#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define lOO 0x3f3f3f3f3f3f3f3f
int n;
///////////////////////////////////////////////////////////

//For Minmun cost 
// N^3
vector<vector<ll>>edg(n + 1, vector<ll>(n + 1, lOO));
void Floyd()
{
	for (int i = 0; i < n; i++) edg[i][i] = 0;
	for (int k = 0; k < n; k++)
		for (int u = 0; u < n; u++)
			for (int v = 0; v < n; v++)
				edg[u][v] = min(edg[u][v], edg[u][k] + edg[k][v]);
}
/////////////////////////////////////////////////////////////////////


//With Paht 
// floyed with path 
vector<vector<ll>>edg(n + 1, vector<ll>(n + 1, lOO));
vector<vector<int>>nxt(n + 1, vector<int>(n + 1, -1));// to get the path 
void floyed_with_path()
{
	for (int i = 0; i < n; i++) {
		nxt[i][i] = i;
		edg[i][i] = 0;
	}
	for (int k = 0; k < n; k++)
	{
		for (int u = 0; u < n; u++)
		{
			for (int v = 0; v < n; v++)
			{
				if (edg[u][v] > edg[u][k] + edg[k][v])
				{
					edg[u][v] = edg[u][k] + edg[k][v];
					nxt[u][v] = nxt[u][k];
				}
			}
		}
	}
}
void path(int source, int target)
{
	if (edg[source][target] != lOO)
	{
		cout << min(edg[source][target], edg[target][source]) << endl;
		cout << source << ' ';
		while (source != target)
		{
			source = nxt[source][target];
			cout << source << ' ';
		}
	}
	else cout << "-1";
	cout << '\n';
}
/////////////////////////////////////////////////////////////////////


// Floyd TransitiveClosure
//To Find if have path
vector<vector<ll>>edg(n + 1, vector<ll>(n + 1, lOO));
void Floyd_TransitiveClosure()
{
	for (int k = 0; k < n; k++)
		for (int u = 0; u < n; u++)
			for (int v = 0; v < n; v++)
				edg[u][v] |= +(edg[u][k] & edg[k][v]);
}
/////////////////////////////////////////////////////////////////////


//To Find MINMAX COST 
// find path such that max value on road is minimum 
vector<vector<ll>>edg(n + 1, vector<ll>(n + 1, lOO));
void Floyd_MinMax()
{
	for (int k = 0; k < n; k++)
		for (int u = 0; u < n; u++)
			for (int v = 0; v < n; v++)
				edg[u][v] = min(edg[u][v], max(edg[u][k], edg[k][v]));
}
/////////////////////////////////////////////////////////////////////


//To Find MaxMin
// find path such that min value on road is maximum
vector<vector<ll>>edg(n + 1, vector<ll>(n + 1, lOO));
void Floyd_MaxMin()
{
	for (int k = 0; k < n; k++)
		for (int u = 0; u < n; u++)
			for (int v = 0; v < n; v++)
				edg[u][v] = max(edg[u][v], min(edg[u][k], edg[k][v]));
}
/////////////////////////////////////////////////////////////////////


//Longest Path 
// Floyd longest Path in DAG (MAX COST)
// find longest path in DAG
vector<vector<ll>>edg(n + 1, vector<ll>(n + 1, lOO));
void Floyd_Longest_Path()
{
	for (int k = 0; k < n; k++)
		for (int u = 0; u < n; u++)
			for (int v = 0; v < n; v++)
				edg[u][v] = max(edg[u][v], max(edg[u][k], edg[k][v]));
}
/////////////////////////////////////////////////////////////////////


//Count paths 	
// Floyd count Paths
vector<vector<ll>>edg(n + 1, vector<ll>(n + 1, lOO));
void Floyd_Count_paths()
{
	for (int k = 0; k < n; k++)
		for (int u = 0; u < n; u++)
			for (int v = 0; v < n; v++)
				edg[u][v] += (edg[u][k] * edg[k][v]);
}
/////////////////////////////////////////////////////////////////////