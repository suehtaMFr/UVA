#include <iostream>
#include <cstring>
#include <vector>

#define f first
#define s second
#define pb push_back

using namespace std;

vector<pair<int,int>> adj[1024];
int dist[1024]; 
const int inf = 999999999;

bool belmanFord(int N){
	memset(dist,inf,sizeof(dist));
	for(int i = 0; i<N-1; i++){
		for(int u = 0; u<N; u++){
			for(auto j : adj[u]){
				if(dist[u] + j.s < dist[j.f]){
					dist[j.first] = dist[u] + j.s;
				}
			}
		}
	}
	for(int u = 0; u<N; u++){
		for(auto j : adj[u]){
			if(dist[u] + j.s < dist[j.f]){
				return false;//ciclo negativo
			}
		}
	}
	return true;
}

int main () {
	
	int ct;
	cin >> ct;
	
	for(int z=0;z<ct;z++)
	{
		int n,m,e,s,p;
		cin >> n >> m;
		for(int y=0;y<m;y++)
		{
			cin >> e >> s >> p;
			adj[e].pb({s,p});
		}
		bool res = belmanFord(n);
		if(!res)
		{
			cout << "possible\n";
		}
		else
		{
			cout << "not possible\n";
		}
		for(int y=0;y<1024;y++)
		{
			adj[y].clear();
		}
	}
}
