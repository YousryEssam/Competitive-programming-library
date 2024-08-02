#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define lOO 0x3f3f3f3f3f3f3f3f
int dx[] = { 0 , 0 , 1,-1 ,-1 ,1 ,-1 , 1 };
int dy[] = { 1 ,-1 , 0, 0 ,-1 ,1 , 1 ,-1 };
///////////////////////////////////////////////////////////
//Dijkstra  2D
int n, m;
vector<vector<int>>grid;
bool valid(int a, int b) { return a >= 0 && a < n && b >= 0 && b < m; }
int dijkstra(int sr, int sc, int tr, int tc) {
    vector<vector<int>>dis(n, vector<int>(m, 2e9));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>>edge;
    dis[sr][sc] = 0;
    edge.push({ dis[sr][sc], {sr,sc} });
    int i, j;
    while (!edge.empty())
    {
        pair<int, pair<int, int>>root = edge.top();
        edge.pop();
        i = root.second.first, j = root.second.second;
        if (i == tr && j == tc) return root.first;
        if (root.first != dis[i][j]) continue;
        for (int ndx = 0; ndx < 4; ndx++)
        {
            if (valid(i + dx[ndx], j + dy[ndx]))
            {
                int x = i + dx[ndx], y = j + dy[ndx];
                if (dis[x][y] > root.first + grid[x][y])
                {
                    dis[x][y] = root.first + grid[x][y];
                    edge.push({ dis[x][y],{x,y} });
                }
            }
        }
    }
}