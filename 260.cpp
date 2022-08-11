#include <iostream>
#include <cstring>

using namespace std;

char mapa[224][224];
bool vis[224][224];
int vx[6]={-1,0,1,1,0,-1},vy[6]={0,1,1,0,-1,-1};

void flodflil(int x,int y,int n,char& res){
	
	if(res==' ')
	{
		vis[x][y]=true;
		for(int k=0;k<6;k++)
		{
			int nx=x+vx[k],ny=y+vy[k];
			if(nx>=0 && nx<n && ny>=0 && ny<n && !vis[nx][ny] && mapa[x][y]==mapa[nx][ny])
			{
				if(mapa[nx][ny]=='w' && ny==n-1)
				{
					res='W';
				}
				if(mapa[nx][ny]=='b' && nx==n-1)
				{
					res='B';
				}
				flodflil(nx,ny,n,res);
			}
			
		}
	}
}

int main () { 
	
	int n,v=1;
	cin >> n;
	while(n)
	{
		char res=' ';
		memset(mapa,' ',sizeof(mapa));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin >> mapa[i][j];
			}
		}
		for(int i=0;res==' ' && i<n;i++)
		{
			memset(vis,false,sizeof(vis));
			flodflil(i,0,n,res);
		}
		for(int j=0;res==' ' && j<n;j++)
		{
			memset(vis,false,sizeof(vis));
			flodflil(0,j,n,res);
		}
		cout << v << " " << res << "\n";
		v++;
		cin >> n;
	}
}
