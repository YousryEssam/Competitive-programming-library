#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(arr, value) memset(arr, value, sizeof(arr))
#define lOO 0x3f3f3f3f3f3f3f3f
/////////////////////////////////////////////////////////// 

int n, l, c;
int mnLec;
int ar[1009];
int dp[1009][509];
int dp2[1009][509];
int getVal(int x){
    if (x == 0) return x;
    if (x <= 10) return -c;
    x -= 10;
    x *= x;
    return x;
}
int minLec(int i = 0, int cur = l){
    if (i == n) return 1;
    int& ret = dp[i][cur];
    if (~ret)return ret;
    ret = 1e8;
    ret = min(ret, minLec(i + 1, l - ar[i]) + 1);
    if (cur >= ar[i])
        ret = min(ret, minLec(i + 1, cur - ar[i]));
    return ret;
}
int minCost(int i = 0, int cur = l){
    if (i >= n) return getVal(cur);
    int& ret = dp2[i][cur];
    if (~ret) return ret;
    ret = 1e8;
    int last = dp[i][cur];
    if (last == minLec(i + 1, l - ar[i]) + 1)
        ret = min(ret, minCost(i + 1, l - ar[i]) + getVal(cur));
    if (cur >= ar[i] && last == minLec(i + 1, cur - ar[i]))
        ret = min(ret, minCost(i + 1, cur - ar[i]));
    return ret;
}
void solve2(int T){
    while (cin >> n && n > 0){
        if (T > 1) cout << endl;
        cin >> l >> c;
        for (int i = 0; i < n; i++) cin >> ar[i];
        mem(dp, -1);
        mem(dp2, -1);
        cout << "Case " << T++ << ":\n";
        cout << "Minimum number of lectures: " << minLec() << endl;
        cout << "Total dissatisfaction index: " << minCost() << endl;
    }
}

//..........................OR....................................// 

int n, l, c, v;
vector<int> topics;
vector<pair<int, int>> memo;
pair<int, int> solve(int idx)
{
    if (idx == n)  return { 0,0 };

    if (memo[idx].first != -1) return memo[idx];

    int min_lec = INT_MAX;
    int min_DI = INT_MAX;
    int time_left = l;

    for (int i = idx; i < n; i++) {
        time_left -= topics[i];
        if (time_left < 0) break;
        int di = 0;
        if (time_left == 0) di = 0;
        else if (time_left <= 10) di = -c;
        else di = (time_left - 10) * (time_left - 10);

        pair<int, int> sub_res = solve(i + 1);
        int lec_needed = sub_res.first + 1;
        di += sub_res.second;
        if (lec_needed < min_lec) {
            min_lec = lec_needed;
            min_DI = di;
        }
        else if (min_lec == lec_needed) {
            min_DI = min(min_DI, di);
        }
    }

    return memo[idx] = { min_lec, min_DI };
}
void solvee(int T)
{
    while (cin >> n && n > 0)
    {
        if (T > 1)
            cout << endl;
        cin >> l >> c;
        memo.assign(n, { -1,-1 });
        topics.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> v;
            topics.push_back(v);
        }
        pair<int, int> res = solve(0);
        cout << "Case " << T << ":\n";
        cout << "Minimum number of lectures: " << res.first << '\n';
        cout << "Total dissatisfaction index: " << res.second << '\n';
        T++;
    }
}

