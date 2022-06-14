#include <iostream>
#include <queue>

#define f first
#define s second

using namespace std;

char mapa[54][54];
bool vis[54][54];
int vx[4]={-1,0,1,0},vy[4]={0,1,0,-1},c;

void bfs(int orix,int oriy,int maxX,int maxY){
	
	queue<pair<int,int>> fila;
	fila.push({orix,oriy});
	vis[orix][oriy]=true;
	while(!fila.empty())
	{
		pair<int,int> u=fila.front();
		fila.pop();
		for(int k=0;k<4;k++)
		{
			int nx=u.f+vx[k],ny=u.s+vy[k];
			if(nx>=0 && nx<maxX && ny>=0 && ny<maxY && !vis[nx][ny])
			{
				vis[nx][ny]=true;
				if(mapa[nx][ny]=='G')
				{
					c++;
				}
				int v=0;
				for(int k=0;k<4;k++)
				{
					int nxx=nx+vx[k],nyy=ny+vy[k];
					if(nxx>=0 && nxx<maxX && nyy>=0 && nyy<maxY && mapa[nxx][nyy]=='T')
					{
						v++;
					}
				}
				if(v==0)
				{
					fila.push({nx,ny});
				}
				
			}
		}
	}
	
}

int main(){
	
	int m,n;
	while(cin >> n >> m)
	{
		int i,j,orix,oriy;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				cin >> mapa[i][j];
				if(mapa[i][j]=='#'||mapa[i][j]=='T')
				{
					vis[i][j]=true;
				}
				else
				{
					if(mapa[i][j]=='P')
					{
						orix=i,oriy=j;
					}
				}
			}
		}
		c=0;
		int k=0;
		for(;k<4;k++)
		{
			int nx=orix+vx[k],ny=oriy+vy[k];
			if(nx>=0 && nx<m && ny>=0 && ny<n && mapa[nx][ny]=='T')
			{
				k=4;
			}
		}
		if(k<=4)
		{
			bfs(orix,oriy,m,n);
		}	
		cout << c << "\n";
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				mapa[i][j]=' ',vis[i][j]=false;
			}
		}
	}
	
}
