#include <iostream>
#include <vector>

using namespace std;

#define pb push_back

vector<int> adj[224];
bool vis[224];
int t=0,c[224];

void reset(){
	
	for(int z=0;z<224;z++)
	{
		vis[z]=false;
		adj[z].clear();
		c[z]=-1;
	}
}

bool dfs (int o){
	
	vis[o]=true;
	t=(t+1)%2;
	c[o]=t;
	for(auto x: adj[o])
	{
		if(c[o]==c[x])return false;
		if(!vis[x])
		{
			dfs(x);
		}
	}
	return true;
}

int main () {
	
	int v;
	cin >> v;
	while(v)
	{
		reset();
		int e;
		cin >> e;
		for(int i=0;i<e;i++)
		{
			int x,y;
			cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		bool res=true;
		for(int i=0;i<v && res;i++)
		{
			if(!vis[i])
			{
				res=dfs(i);
			}
		}
		if(res)
		{
			cout << "BICOLORABLE.\n";
		}
		else
		{
			cout << "NOT BICOLORABLE.\n";
		}
		cin >> v;
	}
}
