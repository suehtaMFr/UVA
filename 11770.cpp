#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

#define pb push_back
#define p push

vector<int> adj[100024];
bool vis[100024];
stack<int> s;

void dfs(int x)
{
	vis[x]=true;
	for(auto i : adj[x])
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
	s.p(x);
}

void dfst(int x)
{
	vis[x]=true;
	for(auto i : adj[x])
	{
		if(!vis[i])
		{
			dfst(i);
		}
	}
}

void reset(int v){
	
	for(int i=0;i<=v;i++)
	{
		adj[i].clear();
	}
}

int main (){
	
	int ct;
	
	cin >> ct;
	
	for(int z=1;z<=ct;z++)
	{
		int v,cn,v1,v2;
		cin >> v >> cn;
		for(int y=0;y<cn;y++)
		{
			cin >>v1 >> v2;
			adj[v1].pb(v2);
		}
		memset(vis,false,sizeof(vis));
		for(int y=1;y<=v;y++)
		{
			if(!vis[y])
			{
				dfs(y);
			}
		}
		memset(vis,false,sizeof(vis));
		int c=0;
		while(!s.empty())
		{
			int it = s.top();
			s.pop();
			if(!vis[it])
			{
				c++;
				dfst(it);
			}
		}
		reset(v);
		cout << "Case " << z << ": " << c << "\n";
	}
}
