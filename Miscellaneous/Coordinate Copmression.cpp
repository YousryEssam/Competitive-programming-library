#include<bits/stdc++.h>
using namespace std;
///////////////////////////////////////////////////////////////////

class coordinateCopmression
{
    map<long long, int>valueTindex;
    vector<long long>indexTovalue;
public:
    coordinateCopmression(vector<long long>& vr)
    {
        indexTovalue = vr;
        sort(indexTovalue.begin(), indexTovalue.end());
        indexTovalue.erase(unique(indexTovalue.begin(), indexTovalue.end()), indexTovalue.end());
        for (int i = 0; i < indexTovalue.size(); i++) valueTindex[indexTovalue[i]] = i;
    }
    int getNew(long long value)
    {
        return valueTindex[value];
    }
    long long getOld(int index)
    {
        return indexTovalue[index];
    }

};