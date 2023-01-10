#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

string reduce(string a)
{
	string x;
	for(int i=0;i<(int)a.size();i++)
		x+=tolower(a[i]);
	return x;
}

int main () {
	
	vector<pair<bool,pair<string,vector<int>>>> v;
	vector<string> st;
	string s;
	while(cin >> s && s!="#")
	{
		string x=reduce(s);
		vector<int> v2(26,0);
		for(int i=0;i<(int)s.size();i++) 
			v2[x[i]-97]++;
		v.push_back({true,{s,v2}});
	}
	for(int i=0;i<(int)v.size();i++)
	{
		if(!v[i].f) continue;
		for(int j=i+1,c;j<(int)v.size();j++)
		{
			if(v[i].s.f.size()!=v[j].s.f.size()) continue;
			c=0;
			for(int k=0;k<26;k++) 
			{
				if(v[i].s.s[k]==v[j].s.s[k]) c++;
			}
			if(c==26) v[i].f=v[j].f=false;
		}
		if(v[i].f) st.push_back(v[i].s.f);
	}
	sort(st.begin(),st.end());
	for(auto x:st) 
		cout << x << "\n";
}
