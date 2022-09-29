#include <iostream>
#include <cstring>
#include <map>

using namespace std;

#define f first
#define s second

char mapa[14][14];
bool vis[14][14];
int dis[14][14];

map<char,pair<int,int>> posi;

void inic(){
	
	posi['N']={-1,0};
	posi['S']={1,0};
	posi['E']={0,1};
	posi['W']={0,-1};
}


bool passeio(int x,int y,int maxX,int maxY,int &ci,int &t){
	
	vis[x][y]=true;
	dis[x][y]=t;
	pair<int,int>p=posi[mapa[x][y]];
	int nx=p.f+x,ny=p.s+y;
	if(nx<0||nx>=maxX||ny<0||ny>=maxY)
	{
		return true;
	}
	if(nx>=0 && nx<maxX && ny>=0 && ny<maxY && vis[nx][ny])
	{
		ci=t-dis[nx][ny];
		t=dis[nx][ny]-1;
		return false;
	}
	t++;
	passeio(nx,ny,maxX,maxY,ci,t);
	return false;
}

int main () {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	inic();
	int l,c,ic;
	cin >> l >> c >> ic;
	while(l || c || ic)
	{
		for(int i=0;i<l;i++)
		{
			for(int j=0;j<c;j++)
			{
				cin >> mapa[i][j]; 
			}
		}
		int t=1,ci=0;
		bool res=passeio(0,ic-1,l,c,ci,t);
		if(res||ci==0)
		{
			cout << t << " step(s) to exit\n";
		}
		else
		{
			cout << t << " step(s) before a loop of "<< ci+1 <<" step(s)\n";
		}
		
		cin >> l >> c >> ic;
		memset(vis,false,sizeof(vis));
		memset(dis,-1,sizeof(dis));
		memset(mapa,' ',sizeof(mapa));
	}
}
