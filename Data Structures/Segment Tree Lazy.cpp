#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(arr, value) memset(arr, value, sizeof(arr))
#define lOO 0x3f3f3f3f3f3f3f3f
///////////////////////////////////////////////////////////


const int N = 1e6 + 1;
vector<int>lazy(4 * N), seg(4 * N);
void build(int idx, int s, int e) {
    if (s == e) {
        //leaf
        seg[idx] = 1;
        return;
    }
    int md = (s + e) >> 1;
    build(2 * idx, s, md);
    build(2 * idx + 1, md + 1, e);
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}
int search(int idx, int s, int e, int l, int r) {
    if (l > e || r < s)return 0;
    if (s >= l && e <= r)return e - s + 1 - seg[idx];
    int md = (s + e) >> 1;
    return search(2 * idx + 1, md + 1, e, l, r) + search(2 * idx, s, md, l, r);
}
void push(int idx, int s, int e) {
    if (!lazy[idx])return;
    seg[idx] += lazy[idx];
    if (s != e) {
        lazy[2 * idx] += lazy[idx];
        lazy[2 * idx + 1] += lazy[idx];
    }
    lazy[idx] = 0;
}
void update(int idx, int s, int e, int l, int r) {
    push(idx, s, e);
    if (l > e || r < s)return;
    if (s >= l && e <= r) {
        lazy[idx]++;
        push(1, s, e);
        return;
    }
    int md = (s + e) >> 1;
    update(2 * idx, s, md, l, r);
    update(2 * idx + 1, md + 1, e, l, r);
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}