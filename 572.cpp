#include <iostream>
#include <queue>

using namespace std;

int vx[8]={-1,-1,0,1,1,1,0,-1},vy[8]={0,1,1,1,0,-1,-1,-1};
char terra[124][124];

void lookingformoney(int x,int y,int maxX,int maxY){
	
	terra[x][y]='p';
	for(int i=0;i<8;i++)
	{
		int nx=x+vx[i],ny=y+vy[i];
		
		if(nx>=1 && nx<=maxX && ny>=1 && ny<=maxY && terra[nx][ny]=='@')
		{
			lookingformoney(nx,ny,maxX,maxY);
		}
	}
}

int main () {
	
	int m,n;
	cin >> m >> n;
	while(m)
	{
		int i,j,money=0;
		queue<int> px,py;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				cin >> terra[i][j];
				if(terra[i][j]=='@')
				{
					px.push(i),py.push(j);
				}
			}
		}
		while(!px.empty())
		{
			int xx=px.front(),yy=py.front();
			px.pop(),py.pop();
			if(terra[xx][yy]=='@')
			{
				money++;
				lookingformoney(xx,yy,m,n);
			}
		}
		cout << money << "\n";
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				terra[i][j]=' ';
			}
		}
		cin >> m >> n;
	}
}
