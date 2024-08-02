#include<bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////
// O(log(n)) 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// less: it is the basic for comparison of two function. Use less_equal for ordered multi-set.
// order_of_key(k): Number of items  strictly smaller than k
// find_by_order(k): kth element in a set (counting from zero)
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main()
{
    int i, j, k, n, m;
    // usage
    ordered_set<int>se;
    se.insert(1);// O(log(n))
    se.insert(2);// O(log(n))
    //  K-th element in a set (counting from zero).
    cout << *se.find_by_order(0) << endl;
    // order_of_key (k) : Number of items strictly smaller than k . 
    cout << se.order_of_key(2) << endl;
    return 0;
}