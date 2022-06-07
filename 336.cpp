#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define s second
#define f first

using namespace std;

map<int,vector<int>> adj;
map<int,vector<int>>::iterator itad;
map<int,int>  dist,cop;
map<int,int>::iterator it;

void bfs(int v){
	
	queue<int> fila;
	fila.push(v);
	dist[v]=0;
	while(!fila.empty())
	{
		int u=fila.front();
		fila.pop();
		int tam=adj[u].size();
		for(int i=0;i<tam;i++)
		{
			if(dist[adj[u][i]]==-1)
			{
				fila.push(adj[u][i]);
				dist[adj[u][i]]=dist[u]+1;
			}
		}
	}
}

int main () {
	
	//~ freopen("input.txt","r",stdin);
	//~ freopen("output.txt","w",stdout);
	
	int cn,d=1;
	cin >> cn;
	while(cn)
	{
		int c=0,c1,c2,ori,dis;
		for(int z=0;z<cn;z++)
		{
			cin >> c1 >> c2;
			adj[c1].push_back(c2);
			adj[c2].push_back(c1);
			dist[c1]=-1;
			dist[c2]=-1;
		}
		cop=dist;
		cin >> ori >> dis;
		while(ori||dis)
		{
			c=0;
			bfs(ori);
			for(it=dist.begin();it!=dist.end();it++)
			{
				if(it->s&&(it->s>dis||it->s==-1))
				{
					c++;
				}
			}
			dist=cop;
			cout << "Case "<< d << ": " << c << " nodes not reachable from node " << ori << " with TTL = " << dis << ".\n";
			d++;
			cin >> ori >> dis;
			
		}
		dist.clear();
		cop.clear();
		adj.clear();
		cin >> cn;
	}
}
