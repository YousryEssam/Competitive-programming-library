#include<bits/stdc++.h>
using namespace std;
//////////////////////////////////////////
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T, typename R> using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main()
{
    int i, j, k, n, m;
    o_map<int, int>mp;
    mp.insert({ 1, 10 });
    mp.insert({ 2, 20 });
    cout << mp.find_by_order(0)->second << endl; ///k th element
    cout << mp.order_of_key(2) << endl; ///number of first elements less than k
    return 0;
}
////////////////