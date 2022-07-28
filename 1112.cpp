#include <iostream>
#include <utility>
#include <vector>
#include <queue>

#define f first
#define s second
#define pb push_back

using namespace std;

const int inf=1e9;

vector<pair<int,int>> adj[124];

int convert(string frase){
	
	int v=0,tam=frase.size();
	for(int z=0;z<tam;z++)
	{
		v=v*10+(frase[z]-48);
	}
	return v;
	
}

int dijikstra(int ori,int des,int n){
	
	vector<int> dist(n,inf);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	dist[ori]=0;
	pq.push({0,ori});
	while(!pq.empty())
	{
		pair<int,int> u=pq.top();
		pq.pop();
		if(u.f>dist[u.s]) continue;
		for(pair<int,int> to:adj[u.s])
		{
			int v=to.s,p=to.f;
			if(dist[v]>u.f+p)
			{
				dist[v]=u.f+p;
				pq.push({dist[v],v});
			}
		}
	}
	return dist[des];
}

int main () {
	
	int ct;
	cin >> ct;
	for(int z=0;z<ct;z++)
	{
		if(z>0)
		{
			cout << "\n"; 
		}
		string frase;
		cin.ignore();
		getline(cin,frase);
		while(frase=="\0")
		{
			getline(cin,frase);
		}
		int qt=convert(frase),s,cr,cn,a,b,t;
		cin >> s >> cr >> cn;
		for(int y=0;y<cn;y++)
		{
			cin >> a >> b >> t;
			adj[a].pb({t,b});
		}
		int c=0;
		for(int i=1;i<=qt;i++)
		{
			int tr=dijikstra(i,s,qt+1);
			if(tr<=cr)
			{
				c++;
			}
		}
		cout << c << "\n";
		for(int y=0;y<=qt;y++)
		{
			adj[y].clear();
		}
	}
}
