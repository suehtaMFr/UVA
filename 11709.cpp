#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

#define pb push_back
#define f first
#define s second
#define p push

map<string,vector<string>> adjp,adjpt;
map<string,vector<string>>::iterator it;
map<string,bool> vis;
vector<string> ele;
stack<string> s;

void dfs(string x)
{
	vis[x]=true;
	for(auto i : adjp[x])
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
	s.p(x);
}

void dfst(string x)
{
	vis[x]=true;
	for(auto i : adjpt[x])
	{
		if(!vis[i])
		{
			dfst(i);
		}
	}
}

void inivis(){
	
	int tam=ele.size();
	for(int i=0;i<tam;i++)
	{
		vis[ele[i]]=false;
	}
}

int main () {
	
	int v,e;
	cin >> v >> e;
	while(v||e)
	{
		cin.ignore();
		string n,n2;
		for(int z=0;z<v;z++)
		{
			getline(cin,n);
			ele.pb(n);
		}
		for(int z=0;z<e;z++)
		{
			getline(cin,n);
			getline(cin,n2);
			
			adjp[n].pb(n2);
			adjpt[n2].pb(n);
		}
		inivis();
		int c=0;
		int tam=ele.size();
		for(int i=0;i<tam;i++)
		{
			if(!vis[ele[i]])
			{
				dfs(ele[i]);
			}
		}
		inivis();
		while(!s.empty())
		{
			string u = s.top();
			s.pop();
			if(!vis[u])
			{
				dfst(u);
				c++;
			}
		}
		adjp.clear();
		adjpt.clear();
		ele.clear();
		cout << c << "\n";
		cin >> v >> e;
	}
}
