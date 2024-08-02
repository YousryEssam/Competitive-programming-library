#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(arr, value) memset(arr, value, sizeof(arr))
#define lOO 0x3f3f3f3f3f3f3f3f
///////////////////////////////////////////////////////////


// Max Histogram Area 
ll maxHistogramArea(vector<ll> v) {
	stack<ll> st;
	ll maxArea = 0, area = 0, i = 0;
	while (i < sz(v)) {
		if (st.empty() || v[st.top()] <= v[i])
			st.push(i++);
		else {
			ll top = st.top();
			st.pop();
			if (st.empty()) area = v[top] * i;
			else area = v[top] * (i - st.top() - 1);
			maxArea = max(maxArea, area);
		}
	}
	while (!st.empty()) {
		ll top = st.top(); st.pop();
		if (st.empty())
			area = v[top] * i;
		else area = v[top] * (i - st.top() - 1);
		maxArea = max(maxArea, area);
	}
	return maxArea;
}