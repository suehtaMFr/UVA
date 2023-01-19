#include <bits/stdc++.h>

using namespace std;

vector<int> kmp(string s){
	
	int k=0,n=(int)s.size();
	vector<int> p(n);
	p[0]=0; 	
	for(int i=1;i<n;i++)
	{
		while(k>0 && s[i]!=s[k]) k=p[k-1];
		if(s[k]==s[i]) k++;
		p[i]=k;
	}
	return p;
}

bool match(string t,string s,vector<int> p) {
	
	vector<int> r;
	int k=0,szt=(int)t.size(),szs=(int)s.size();
	for(int i=0;i<szt;i++)
	{
		while(k>0 && t[i]!=s[k]) k=p[k-1];
		if(t[i]==s[k]) k++;
		if(k==szs) return true;
	}
	return false;
}

int main () {
	
	int tc;
	cin >> tc;
	while(tc--)
	{
		int q;
		string s,x;
		cin >> s >> q;
		for(int i=0;i<q;i++)
		{
			cin >> x;
			cout << (match(s,x,kmp(x)) ? 'y':'n') << "\n";
		}
	}
}
