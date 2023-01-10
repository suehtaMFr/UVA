#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

char mat[54][54];
bool mapa[54][54];
int vx[4]={-1,0,1,0},vy[4]={0,1,0,-1},v;

queue<pair<int,int>> path;

void flodflilpt(int x,int y,int maxX,int maxY);

void flodflilas(int x,int y,int maxX,int maxY){
	
	mapa[x][y]=true;
	
	for(int k=0;k<4;k++)
	{
		int nx=x+vx[k],ny=y+vy[k];
		if(nx>=0 && nx<maxX && ny>=0 && ny<maxY && !mapa[nx][ny] && mat[nx][ny]=='X')
		{
			v++;
			flodflilpt(nx,ny,maxX,maxY);
		}
	}
	for(int k=0;k<4;k++)
	{
		int nx=x+vx[k],ny=y+vy[k];
		if(nx>=0 && nx<maxX && ny>=0 && ny<maxY && !mapa[nx][ny] && mat[nx][ny]=='*') flodflilas(nx,ny,maxX,maxY);
	}
}

void flodflilpt(int x,int y,int maxX,int maxY){
	
	mapa[x][y]=true;
	
	path.push({x,y});
	for(int k=0;k<4;k++)
	{
		int nx=x+vx[k],ny=y+vy[k];
		if(nx>=0 && nx<maxX && ny>=0 && ny<maxY && !mapa[nx][ny] && mat[nx][ny]=='X') flodflilpt(nx,ny,maxX,maxY);
	}
}

void recoverx(int maxX,int maxY){
	
	while(!path.empty())
	{
		int x=path.front().f,y=path.front().s;
		path.pop();
		for(int k=0;k<4;k++)
		{
			int nx=x+vx[k],ny=y+vy[k];
			if(nx>=0 && nx<maxX && ny>=0 && ny<maxY && !mapa[nx][ny]) flodflilas(nx,ny,maxX,maxY);
		}
	}
}

int main () {
	
	int n,m,vv=0;
	cin >> m >> n;
	while(n || m)
	{
		vector<int> res;
		while(!path.empty())
		{
			path.pop();
		}
		for(int z=0;z<=50;z++)
		{
			for(int y=0;y<=50;y++)
			{
				mat[z][y]=' ';mapa[z][y]=false;
			}
		}
		queue<pair<int,int>> qd,qp;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin >> mat[i][j];
				if(mat[i][j]=='*')
				{
					qd.push({i,j});
				}
				else
				{
					if(mat[i][j]=='X')
					{ 
						qp.push({i,j});
					}
					else
					{
						mapa[i][j]=true;
					}
				}
			}
		}
		while(!qd.empty())
		{
			v=0;
			int x=qd.front().f,y=qd.front().s;
			qd.pop();
			if(!mapa[x][y])
			{
				flodflilas(x,y,n,m);
				recoverx(n,m);
				if(v) res.push_back(v);
			}
		}
		while(!qp.empty())
		{
			int x=qp.front().f,y=qp.front().s;
			qp.pop();
			if(!mapa[x][y])
			{
				flodflilpt(x,y,n,m);
				res.push_back(1);
			}
		}
		cout << "Throw " << ++vv << "\n"; 
		sort(res.begin(),res.end());
		for(int i=0;i<(int)res.size();i++)
		{
			cout << res[i];
			if(i<(int)res.size()-1) cout << " ";
		}
		cout << "\n\n";
		cin >> m >> n;
	}
}
