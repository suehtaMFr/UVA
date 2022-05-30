#include <iostream>
#include <queue>

using namespace std;

int vx[8]={-1,-1,0,1,1,1,0,-1},vy[8]={0,1,1,1,0,-1,-1,-1};
char sky[102][102];

void starsFood(int x,int y,int maxX,int maxY,int &so){
	
	sky[x][y]='o';
	for(int i=0;i<8;i++)
	{
		int nx=x+vx[i],ny=y+vy[i];
		
		if(nx>=0 && nx<maxX && ny>=0 && ny<maxY && sky[nx][ny]=='*')
		{
			so++;
			starsFood(nx,ny,maxX,maxY,so);
		}
	}
}

int main () {
	
	int m,n;
	
	cin >> m >> n;
	
	while(m || n)
	{
		queue<int> px,py;
		int i,j,s=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				cin >> sky[i][j];
				if(sky[i][j]=='*')
				{
					s++;
					px.push(i),py.push(j);
				}
			}
		}
		while(!px.empty())
		{
			int ss=1,xx=px.front(),yy=py.front();
			px.pop(),py.pop();
			starsFood(xx,yy,m,n,ss);
			if(ss>1)
			{
				s=s-ss;
			}
		}
		cout << s << "\n";
		
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				sky[i][j]=' ';
			}
		}
		cin >> m >> n;
	}
}
