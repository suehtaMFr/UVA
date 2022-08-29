#include <iostream>
#include <vector>

using namespace std;

#define pb push_back

bool vis[50024];
vector<int> adj[50024];
bool marcado[50024];
void dfs(int o,int& c){
	vis[o]=true;
	c++;
	for(auto u: adj[o])
	{
		if(!vis[u])
		{
			dfs(u,c);
		}
	}
	vis[o]=false;
	marcado[o]=true;
}

int main () {
	int ct;
	cin >> ct;
	for(int z=1;z<=ct;z++)
	{
		int v,v1,v2;
		cin >> v;
		for(int y=0;y<v;y++)
		{
			cin >> v1 >> v2; v1--;v2--;
			adj[v1].pb(v2);
		}
		int m=-1;
		int resposta;
		for(int y=0;y<v;y++)
		{
			int c=0;
			
			if(!marcado[y])dfs(y,c);
			if(c>m)
			{
				m=c;
				resposta=y+1;
			}
		}
		for(int i = 0; i < 50024; i++){
			adj[i].clear();
			vis[i]=marcado[i]=false;
		}
		cout <<"Case "<<z<<": "<< resposta << "\n";
	}
}
