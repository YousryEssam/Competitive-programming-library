#include<bits/stdc++.h>
using namespace std;
#define ll long long
///////////////////////////////////////////////////////////////////
// Number systems conversions 
long long toDicimal(string s,int base){
    long long num=0;
    for(int i=s.size()-1,j=0 ;i>=0; i--,j++){
        int n;
        if(s[i]>='A')  n=s[i]-55;
        else  n=s[i]-48; 
        num+=pow(base,j)*n;
    }
    return num;
}
string fromDicimal(long long n,int base){
    string s="";
    while(n>0){
        int x=n%base;
        if(x>9) s+=((char)(x+55));
        else s+=to_string(x);
        n/=base;
    }
    if(s.empty())   s="0";
    reverse(s.begin(),s.end());
    return s;
}