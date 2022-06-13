#include <iostream>
#include <queue>

using namespace std;

int mapa[30][30],vx[8]={-1,-1,0,1,1,1,0,-1},vy[8]={0,1,1,1,0,-1,-1,-1};

void bludfill(int x,int y,int maxX,int maxY,int &so){
	
	mapa[x][y]=0;
	so++;
	for(int k=0;k<8;k++)
	{
		int nx=x+vx[k],ny=y+vy[k];
		if(nx>=0&&nx<maxX&&ny>=0&&ny<maxY&&mapa[nx][ny])
		{
			bludfill(nx,ny,maxX,maxY,so);
		}
	}
}

int main () {
	
	int q;
	cin >> q;
	for(int z=0;z<q;z++)
	{
		if(z)
		{
			cout << "\n";
		}
		string frase;
		queue<int> px,py;
		int i,j,n,v=0;
		getline(cin,frase);
		while(frase=="\0"&&v<2)
		{
			getline(cin,frase);
			v++;
		}
		for(i=0;frase!="\0";i++)
		{
			n=frase.size();
			for(j=0;j<n;j++)
			{
				mapa[i][j]=(frase[j]-48);
				if(mapa[i][j]){px.push(i),py.push(j);}
			}
			getline(cin,frase);
		}
		int mm=i;
		int m=0;
		while(!px.empty())
		{
			int xx=px.front(),yy=py.front();px.pop(),py.pop();
			if(mapa[xx][yy])
			{
				int s=0;
				bludfill(xx,yy,mm,n,s);
				if(m<s)
				{
					m=s;
				}
			}
		}
		cout << m << "\n";
	}
}
