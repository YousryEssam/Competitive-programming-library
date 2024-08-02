#include<bits/stdc++.h>
using namespace std;
#define ll long long
///////////////////////////////////////////////////////////////////

// max consecutive sum in range segmant tree  

ll n, l, r;
vector<ll>v;
struct nodeData{
    ll bestPre = 0;
    ll bestSuf = 0;
    ll nodeSum = 0;
    ll nodeAns = 0;
    nodeData(ll val) {nodeSum = nodeAns = bestPre = bestSuf = val;}
    nodeData() {}
};
vector<nodeData>seg;
nodeData mergeNodes(int a, int b){
    nodeData ans(0);
    ans.nodeSum = seg[a].nodeSum + seg[b].nodeSum;
    ans.bestPre = max({ seg[a].bestPre , seg[a].nodeSum + seg[b].bestPre });
    ans.bestSuf = max({ seg[b].bestSuf , seg[b].nodeSum + seg[a].bestSuf });
    ans.nodeAns = max({ seg[a].nodeAns , seg[b].nodeAns ,
                       seg[a].bestSuf + seg[b].bestPre  , seg[a].nodeSum + seg[b].nodeSum });
    return ans;
}
nodeData mergeNodes(nodeData a, nodeData b){
    nodeData ans(0);
    ans.nodeSum = a.nodeSum + b.nodeSum;
    ans.bestPre = max({ a.bestPre , a.nodeSum + b.bestPre });
    ans.bestSuf = max({ b.bestSuf , b.nodeSum + a.bestSuf });
    ans.nodeAns = max({ a.nodeAns , b.nodeAns ,
                       a.bestSuf + b.bestPre , a.nodeSum + b.nodeSum });
    return ans;
}
nodeData infoQuery(int idx = 1, int s = 1, int e = n) {
    if (s > r || e < l) {
        nodeData temp(-1000000000);
        return temp;
    }
    if (s >= l && e <= r) return seg[idx];
    int left = 2 * idx;
    int right = 2 * idx + 1;
    nodeData LN = infoQuery(left, s, (s + e) / 2);
    nodeData RN = infoQuery(right, (s + e) / 2 + 1, e);
    return mergeNodes(LN, RN);
}
void buildSegTree(int idx = 1, int s = 1, int e = n)
{
    if (s == e) {
        seg[idx].bestPre = v[s];
        seg[idx].bestSuf = v[s];
        seg[idx].nodeSum = v[s];
        seg[idx].nodeAns = v[s];
        return;
    }
    int left = 2 * idx;
    int right = 2 * idx + 1; 
    buildSegTree(left, s, (s + e) / 2);
    buildSegTree(right, (s + e) / 2 + 1, e);
    seg[idx] = mergeNodes(left, right);
}
void runRMQ() {
    cin >> n;
    v.resize(n + 1);
    seg.resize(n * 4 + 100);
    for (int i = 1; i <= n; i++) cin >> v[i];
    buildSegTree();
    int q; cin >> q;
    while (q--){
        cin >> l >> r;
        nodeData ans = infoQuery();
        cout << ans.nodeAns << endl;
    }
}