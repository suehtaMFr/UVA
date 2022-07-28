#include <iostream>
#include <cstring>

#define f first
#define s second
#define pb push_back

using namespace std;

bool vis[24][24];
int vx[4]={-1,0,1,0},vy[4]={0,1,0,-1};

void flodflil(int x,int y,int maxX,int maxY,char il,char mapa[][24],int & c){
	
	vis[x][y]=true;
	int nx,ny;
	for(int k=0;k<4;k++)
	{
		nx=x+vx[k],ny=y+vy[k];
		if(nx>=0 && nx<maxX && ny>=0 && ny<maxY && mapa[nx][ny]==il && !vis[nx][ny])
		{
			c++;
			flodflil(nx,ny,maxX,maxY,il,mapa,c);
		}
	}
	if(y==0)
	{
		ny=y+maxY-1;
		if(ny<maxY && mapa[x][ny]==il && !vis[x][ny])
		{
			c++;
			flodflil(x,ny,maxX,maxY,il,mapa,c);
		}
	}
	if(y==maxY-1)
	{
		ny=maxY-1-y;
		if(ny>=0 && mapa[x][ny]==il && !vis[x][ny])
		{
			c++;
			flodflil(x,ny,maxX,maxY,il,mapa,c);
			
		}
	}
}

int main () {
	
	int m,n;
	while(cin >> m >> n)
	{
		char mapa[24][24];
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin >> mapa[i][j];
			}
		}
		int ipx,ipy;
		cin >> ipx >> ipy;
		char ilha=mapa[ipx][ipy];
		flodflil(ipx,ipy,m,n,ilha,mapa,c);
		int mm=-1;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(mapa[i][j]==ilha && !vis[i][j])
				{
					c=1;
					flodflil(i,j,m,n,ilha,mapa,c);
					if(c>mm)
					{
						mm=c;
					}
				}
			}
		}
		if(mm==-1)
		{
			mm=0;
		}
		cout << mm << "\n";
		memset(vis,false,sizeof(vis));
	}
}
