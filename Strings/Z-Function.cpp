#include<bits/stdc++.h>
using namespace std;
///////////////////////////////////////////////////////////////////


//z - function for calculate greatest number of characters begin from i and equal prefix of string s.
// Z-function algorithm to find all occurrences of a substring within a string.
vector<int> Z_fun(string & s)
{
	vector<int>Z(s.size(), 0);
	for (int i = 1, l = 0, r = 0; i < (int)s.size(); i++)
	{
		if (r >= i)
			Z[i] = min(r - i + 1, Z[i - l]);
		while (i + Z[i] < (int)s.size() && s[Z[i]] == s[i + Z[i]])++Z[i];
		if (i + Z[i] - 1 > r)
			l = i, r = i + Z[i] - 1;
	}
	return Z;
}
// for match sub-string make new string sub+$+str and make z-function on it 
vector<int> match_substring(string & s, string & sub) // return idx than have sub str 
{
	string New = sub + "$" + s;
	vector<int>Z = Z_fun(New);
	vector<int>ndx;
	for (int i = 0; i < (int)New.size(); i++)
		if (Z[i] == sub.size())
			ndx.push_back(i - sub.size() - 1);
	return ndx;
}