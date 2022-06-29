#include <iostream>
#include <utility>
#include <cstring>
#include <vector>
#include <queue>

#define f first
#define s second

using namespace std;

const int inf=1e9;
int mapa[1024][1024],dist[1024][1024],vetx[4]={-1,0,1,0},vety[4]={0,1,0,-1};

int dijikstra(int maxX,int maxY){
	for(int i=0;i<maxX;i++)
	{
		for(int j=0;j<maxY;j++)
		{
			dist[i][j]=inf;
		}
	}
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
	dist[0][0]=mapa[0][0];
	pq.push({mapa[0][0],{0,0}});
	while(!pq.empty())
	{
		pair<int,pair<int,int>> u=pq.top();
		pq.pop();
		if(u.f>dist[u.s.f][u.s.s]) continue;
		for(int k=0;k<4;k++)
		{
			int nx=u.s.f+vetx[k],ny=u.s.s+vety[k];
			if(nx>=0 && nx<maxX && ny>=0 && ny<maxY)
			{
				int vx=nx,vy=ny,p=mapa[vx][vy];
				if(dist[vx][vy]>u.f+p)
				{
					dist[vx][vy]=u.f+p;
					pq.push({dist[vx][vy],{vx,vy}});
				}
			}
		}
	}
	return dist[maxX-1][maxY-1];
}

int main () {
	
	int t;
	cin >> t;
	for(int z=0;z<t;z++)
	{
		int m,n,i,j;
		cin >> m >> n;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				cin >> mapa[i][j];
			}
		}
		int d=dijikstra(m,n);
		cout << d << "\n";
	}	
}
