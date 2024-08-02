#include<vector>
#include<stack>
using namespace std;
/////////////////////////////////////////////////
//Next Greater Element 
// return vector have idx of NGE in origenal arr
vector<int>NextGreaterElement(vector<int>& v){
    vector<int> ans(v.size(), -1);
    stack<int>st;
    int siz = v.size();
    for (int i = 0; i < siz; i++){
        while (!st.empty() && v[st.top()] < v[i]){
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}