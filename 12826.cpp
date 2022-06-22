#include <iostream>
#include <utility>
#include <cstring>
#include <vector>
#include <queue>

#define f first
#define s second

using namespace std;

char mapa[9][9];
bool vis[9][9];
int dis[9][9];
int vkx[8]={-1,-1,0,1,1,1,0,-1},vky[8]={0,1,1,1,0,-1,-1,-1};

int kingBfs(int orix,int oriy,int desx,int desy){

	vis[orix][oriy]=true;
	dis[orix][oriy]=0;
	mapa[orix][oriy]='E';
	queue<pair<int,int> > fila;
	fila.push({orix,oriy});
	while(!fila.empty())
	{
		pair<int,int> u=fila.front();
		fila.pop();
		if(u.f==desx && u.s==desy)
		{
			return dis[u.f][u.s];
		}
		for(int k=0;k<8;k++)
		{
			int nx=u.f+vkx[k],ny=u.s+vky[k];
			if(nx>=1 && nx<=8 && ny>=1 && ny<=8 && !vis[nx][ny])
			{
				mapa[nx][ny]='V';
				vis[nx][ny]=true;
				dis[nx][ny]=dis[u.f][u.s]+1;
				fila.push({nx,ny});
			}
		}
	}
	return -1;
}

int main () {

	int r1,c1,r2,c2,r3,c3,v=0;

	while(cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3)
	{
		v++;
		memset(vis,false,sizeof(vis));
		memset(dis,-1,sizeof(dis));
		memset(mapa,'.',sizeof(mapa));
		vis[r3][c3]=true;
		mapa[r3][c3]='Z';
		int d=kingBfs(r1,c1,r2,c2);
		cout << "Case " << v << ": " << d << "\n";
	}
}
