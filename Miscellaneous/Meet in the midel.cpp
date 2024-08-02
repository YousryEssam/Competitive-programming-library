#include<bits/stdc++.h>
using namespace std;
#define ll long long
///////////////////////////////////////////////////////////////////

//Meet in the midel 
const int N = 40;
ll X[2000005], Y[2000005], arr[N];
void calcSubSet(ll A[], ll X[], int n, int c) 
{
    for (int i = 0; i < (1 << n); i++) 
    {
        ll s = 0;
        for (int j = 0; j < n; j++) 
        {
            if (i & (1 << j))
                s += A[j + c];
        }
        X[i] = s;
    }
}
ll solve(ll a[], int n, ll S) 
{
    //subsets of 1st and 2nd halves
    calcSubSet(a, X, n / 2, 0);
    calcSubSet(a, Y, n - n / 2, n / 2);
    int sizeX = 1 << (n / 2);
    int sizeY = 1 << (n - n / 2);
    //sort Y
    sort(Y, Y + sizeY);
    //keep track of max element
    ll max = 0;
    for (int i = 0; i < sizeX; i++) 
    {
        if (X[i] <= S)
        {
            int p = lower_bound(Y, Y + sizeY, S - X[i]) - Y;
            if (p == sizeY || Y[p] != (S - X[i])) p--;
            if ((Y[p] + X[i]) > max) max = Y[p] + X[i];
        }
    }
    return max;
}
int main()
{
    ll n ,s; cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> arr[i]; 
    cout << solve(arr, n, s);
}
