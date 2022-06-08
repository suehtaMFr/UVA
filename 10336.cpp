#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define f first
#define s second

int vx[4]={-1,0,1,0},vy[4]={0,1,0,-1};

bool order(pair<char,int> a,pair<char,int>b){
	if(a.s!=b.s)
	{
		return a.s>b.s;
	}
	return a.f<b.f;
}

void rankflod(int x,int y,vector<char> m[],vector<bool> ptv[],int maxX,int maxY){
	
	ptv[x][y]=true;
	for(int k=0;k<4;k++)
	{
		int nx=x+vx[k],ny=y+vy[k];
		if(nx>=0 && nx<maxX && ny>=0 && ny<maxY && !ptv[nx][ny] && m[nx][ny]==m[x][y])
		{
			rankflod(nx,ny,m,ptv,maxX,maxY);
		}
	}
}

int main () {
	
	int l;
	
	cin >> l;
	
	for(int z=0;z<l;z++)
	{
		int n,m,i,j,ind=0;
		cin >> m >> n;
		vector<char> mat[m];
		vector<bool> vis[m];
		vector<pair<char,int>> repet;
		char c;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				int y=0;
				cin >> c;
				for(;y<ind && repet[y].f!=c;y++);
				if(y==ind)
				{
					ind++;
					repet.push_back({c,0});
				}
				mat[i].push_back(c);
				vis[i].push_back(false);
			}
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(!vis[i][j])
				{
					int y=0;
					for(;y<ind && repet[y].f!=mat[i][j];y++);
					repet[y].s++;
					rankflod(i,j,mat,vis,m,n);
				}
			}
		}
		sort(repet.begin(),repet.end(),order);
		cout << "World #" << z+1 <<"\n";
		for(int x=0;x<ind;x++)
		{
			cout << repet[x].f << ": " << repet[x].s<< "\n";
		}
 	}	
}
