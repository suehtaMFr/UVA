#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define pb push_back

bool vis[2024];
vector<int> adj[2024];

void dfs(int o,int& c){
	
	vis[o]=true;
	c++;
	for(auto x: adj[o])
	{
		if(!vis[x])
		{
			dfs(x,c);
		}
	}
}

int main () {
	
	int n,m;
	cin >> n >> m;
	while(n||m)
	{
		int v1,v2,p;
		for(int z=0;z<m;z++)
		{
			cin >> v1 >> v2 >> p;
			if(--p)
			{
				adj[v1].pb(v2);
				adj[v2].pb(v1);
			}
			else
			{
				adj[v1].pb(v2);
			}
		}
		int i=0;
		for(int z=1;z<=n;z++)
		{
			memset(vis,false,sizeof(vis));
			int c=0;
			dfs(z,c);
			if(c==n)
			{
				i++;
			}
		}
		if(i==n)
		{
			cout << "1\n";
		}
		else
		{
			cout << "0\n";
		}
		for(int z=0;z<2024;z++)
		{
			adj[z].clear();
		}
		cin >> n >> m;
	}
}
