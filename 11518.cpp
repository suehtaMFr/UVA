#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define pb push_back

vector<int> adj[10024];
bool vis[10024];

void flodflil(int o,int& dom){
	
	dom++;
	vis[o]=true;
	queue<int>q;
	q.push(o);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		int tam=adj[u].size();
		for(int x=0;x<tam;x++)
		{
			int px=adj[u][x];
			if(!vis[px])
			{
				vis[px]=true;
				dom++;
				q.push(px);
			}
		}
	}
		
}

int main () { 
	
	int ct;
	cin >> ct;
	for(int z=0;z<ct;z++)
	{
		int n,m,l,c,c2,dom=0,e;
		cin >> n >> m >> l;
		for(int y=0;y<m;y++)
		{
			cin >> c >> c2;
			adj[c].pb(c2);
		}
		for(int y=0;y<l;y++)
		{
			cin >> e;
			if(!vis[e])
			{
				flodflil(e,dom);
			}
		}
		cout << dom << "\n";
		memset(vis,false,sizeof(vis));
		for(int y=0;y<10024;y++)
		{
			adj[y].clear();
		}
	}
}
