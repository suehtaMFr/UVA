#include <iostream>
#include <cstring>
#include <queue>
#include <map>

#define f first
#define s second

using namespace std;

char mapa[9][9];
bool vis[9][9];
int vx[4]={-1,0,1,0},vy[4]={0,1,0,-1};
map<char,int> tra;

void ini(){
	
	tra['X']=0;//preto
	tra['O']=1;//branco
}

void flodflil(int x,int y,int *v,int &java){
	
	vis[x][y]=true;
	for(int k=0;k<4;k++)
	{
		int nx=x+vx[k],ny=y+vy[k];
		if(nx>=0 && nx<9 && ny>=0 && ny<9 && !vis[nx][ny])
		{
			if(mapa[nx][ny]=='.')
			{
				java++;
				flodflil(nx,ny,v,java);
			}
			else
			{
				v[tra[mapa[nx][ny]]]=1;
			}
		}
	}
}

int main () {
	
	int ct;
	
	cin >> ct;
	
	ini();
	
	for(int z=0;z<ct;z++)
	{
		memset(vis,false,sizeof(vis));
		queue<pair<int,int>> eb;
		int pp=0,pb=0;
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				cin >> mapa[i][j];
				if(mapa[i][j]=='.')
				{
					eb.push({i,j});
				}
				else
				{
					if(mapa[i][j]=='X')
					{
						pp++;
					}
					else
					{
						pb++;
					}
				}
			}
		}
		while(!eb.empty())
		{
			int ci=eb.front().f,cj=eb.front().s;
			eb.pop();
			int v[2],java=1;
			memset(v,0,sizeof(v));
			if(!vis[ci][cj])
			{
				flodflil(ci,cj,v,java);
				if(v[0]>v[1])
				{
					pp+=java;
				}
				else
				{
					if(v[0]<v[1])
					{
						pb+=java;
					}
				}
			}
		}
		cout << "Black " << pp << " White " << pb << "\n";
	}
}
