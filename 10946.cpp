#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>

using namespace std;

#define f first
#define s second
#define pb push_back

char mapa[55][55];
bool vis[55][55];
int vx[4]={-1,0,1,0},vy[4]={0,1,0,-1};

void flodflil(int x,int y,int maxX,int maxY,int& c){
	
	c++;
	vis[x][y]=true;
	for(int k=0;k<4;k++)
	{
		int nx=x+vx[k],ny=y+vy[k];
		if(nx>=0 && nx<maxX && ny>=0 && ny<maxY && !vis[nx][ny] && mapa[x][y]==mapa[nx][ny])
		{
			flodflil(nx,ny,maxX,maxY,c);
		}
	}
}

bool ordena(pair<char,int> a,pair<char,int> b){
	
	if(a.s!=b.s)
	{
		return (a.s>b.s);
	}
	return (a.f<b.f);
}

int main (){
	
	int n,m,v=1;
	cin >> n >> m;
	while(n||m)
	{
		vector<pair<char,int>> pp;
		memset(vis,false,sizeof(vis));
		memset(mapa,'.',sizeof(mapa));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin >> mapa[i][j];
				if(mapa[i][j]=='.')
				{
					vis[i][j]=true;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				int c=0;
				if(!vis[i][j])
				{
					flodflil(i,j,n,m,c);
					pp.pb({mapa[i][j],c});
				}
			}
		}
		cout << "Problem " << v << ":\n";
		sort(pp.begin(),pp.end(),ordena);
		int tam=pp.size();
		for(int k=0;k<tam;k++)
		{
			cout << pp[k].f << " " << pp[k].s << "\n";
		}
		cin >> n >> m;
		v++;
	}		
}
