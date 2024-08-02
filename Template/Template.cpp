#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define sz(x) (int)x.size()
#define lOO 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(), x.end()
#define format(n) cout << fixed << setprecision(n)
#define mem(arr, value) memset(arr, value, sizeof(arr))
#define PI 3.1415926535
#define EPS 1e-9
using namespace std;
int dx[] = { 0 , 0 , 1,-1 ,-1 ,1 ,-1 , 1 };
int dy[] = { 1 ,-1 , 0, 0 ,-1 ,1 , 1 ,-1 };
void fastIO(){
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
}
void filesIO(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
//==========================functions & vars & DS=======================//
void solve(int T){

}
//==========================functions & vars & DS=======================//
int main(){
    fastIO();
    int t = 1; //cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
    return 0 ; 
}