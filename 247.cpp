#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

#define p push
#define f first
#define s second
#define pb push_back

map<string,vector<string>> adjp,adjpt;//adjputaria
map<string,bool> vis,vist;
stack<string> st;

void dfs(string o){
	vis[o]=true;
	for(string u: adjp[o])
	{
		if(!vis[u])
		{
			dfs(u);
		}
	}
	st.push(o);
}

void dfst(string o){
	
	vist[o]=true;
	for(string u: adjpt[o])
	{
		if(!vist[u])
		{
			cout << ", " << u;
			dfst(u);
		}
	}
}

int main () {
	
	int v,e,ll=1;
	cin >> v >> e;
	while(v || e)
	{
		if(ll>1)cout <<"\n";
    
		for(int z=0;z<e;z++)
		{
			string v1,v2;
			cin >> v1 >> v2;
			adjp[v1].pb(v2);
			adjpt[v2].pb(v1);
			vist[v1]=vist[v2]=vis[v1]=vis[v2]=false;
		}
		for(auto x: adjp)
		{
			if(!vis[x.f])
			{
				dfs(x.f);
			}
		}
		ti=0;
		cout << "Calling circles for data set " << ll << ":\n";
		while(!st.empty())
		{
			string u = st.top();
			st.pop();
			if(!vist[u])
			{
				cout << u;
				dfst(u);
				cout << "\n";
			}
		}
		cin >> v >> e;
		vis.clear(),vist.clear(),adjp.clear(),adjpt.clear();
		ll++;
	}
}
