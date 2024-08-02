#include<bits/stdc++.h>
using namespace std;
///////////////////////////////////////////////////////////////////
vector<long long>getDivisorsSorted(long long n) {//O(sqrt(n))
    vector<long long>divisors;
    stack<long long>st;
    for(long long i=1; i * i <= n; i++){
        if(n%i==0){
            divisors.push_back(i);
            if((n/i)!=i)  st.push(n/i);
        }  
    }
    while(!st.empty()){
        divisors.push_back(st.top());
        st.pop();
    }
    return divisors;
}