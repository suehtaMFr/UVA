#include <iostream>
#include <vector>
#include <cstdio>

#define pb push_back

using namespace std;

vector<vector<char> > mapa(100),auxm(100);
vector<vector<bool> > vis(100),auxb(100);
int c,vx[8]={-1,-1,0,1,1,1,0,-1},vy[8]={0,1,1,1,0,-1,-1,-1};

void flodflil(int x,int y,int maxX,int maxY){
	
	mapa[x][y]='*';
	c++;
	vis[x][y]=true;
	for(int k=0;k<8;k++)
	{
		int nx=x+vx[k],ny=y+vy[k];
		if(nx>=1 && nx<=maxX && ny>=1 && ny<=maxY && !vis[nx][ny])
		{
			flodflil(nx,ny,maxX,maxY);
		}
	}
}

int main () {
	
	int n;
	cin >> n;
	string linha;
	cin.ignore();
	for(int z=0;z<n;z++)
	{
		if(z)
		{
			cout << "\n";
		}
		getline(cin,linha);
		while(linha=="\0")
		{
			getline(cin,linha);
		}
		int i=1,mx=0,j,tam;
		while(linha!="\0"&&((int)linha[0]<=47||(int)linha[0]>=58))
		{
			tam=linha.size();
			vis[i].pb(true);
			mapa[i].pb('L');
			for(j=1;j<=tam;j++)
			{
				mapa[i].pb(linha[j-1]);
				if(mapa[i][j]=='W')
				{
					vis[i].pb(false);
				}
				else
				{
					vis[i].pb(true);
				}
			}
			i++;
			mx++;
			getline(cin,linha);
		}
		auxm=mapa;
		auxb=vis;
		while(linha!="\0")
		{
			int s1=0,s2=0,t=linha.size(),p;
			for(p=0;p<t&&linha[p]!=' ';p++)
			{
				s1=s1*10+(linha[p]-48);
			}
			for(p++;p<t;p++)
			{
				s2=s2*10+(linha[p]-48);
			}
			c=0;
			flodflil(s1,s2,mx,tam);
			cout << c << "\n";
			vis=auxb;
			mapa=auxm;
			getline(cin,linha);
		}
		for(int o=0;o<=mx;o++)
		{
			mapa[o].clear(),vis[o].clear(),auxm[o].clear(),auxb[o].clear();
		}
	}
}
