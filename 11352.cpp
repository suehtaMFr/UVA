#include <iostream>
#include <utility>
#include <vector>
#include <queue>

#define f first
#define s second

using namespace std;

int vcx[8]={-2,-1,1,2,2,1,-1,-2},vcy[8]={1,2,2,1,-1,-2,-2,-1},vkx[8]={-1,-1,0,1,1,1,0,-1},vky[8]={0,1,1,1,0,-1,-1,-1};

void beterBfs(int orix,int oriy,int maxX,int maxY,string mapa[],vector<vector<pair<int,bool>>> &distv){
	
	for(int i=0;i<maxX;i++)
	{
		vector<pair<int,bool>> aux;
		for(int j=0;j<maxY;j++)
		{
			aux.push_back({-1,false});
		}
		distv.push_back(aux);
	}
	distv[orix][oriy].f=0;
	distv[orix][oriy].s=true;
	queue<pair<int,int>> fila;
	fila.push({orix,oriy});
	while(!fila.empty())
	{
		pair<int,int> u=fila.front();
		fila.pop();
		mapa[u.f][u.s]='v';
		for(int k=0;k<8;k++)
		{
			int nx=u.f+vkx[k],ny=u.s+vky[k];
			if(nx>=0 && nx<maxX && ny>=0 && ny<maxY && !distv[nx][ny].s && (mapa[nx][ny]=='.'||mapa[nx][ny]=='B'))
			{
				fila.push({nx,ny});
				distv[nx][ny].f=distv[u.f][u.s].f+1;
				distv[nx][ny].s=true;
			}
		}
	}
	
}

int main () {
	
	int t;
	cin >> t;
	for(int l=0;l<t;l++)
	{
		queue<int> cx,cy;
		int m,n,i,j;
		cin >> m >> n;
		string mapa[m];
		vector<vector<pair<int,bool>>> distv;
		int orix,oriy,desx,desy;
		char aux;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				cin >> aux;
				mapa[i]+=aux;
				if(mapa[i][j]!='.')
				{
					if(mapa[i][j]=='Z')
					{
						cx.push(i),cy.push(j);
					}
					else
					{
						if(mapa[i][j]=='A')
						{
							orix=i,oriy=j;
						}
						else
						{
							if(mapa[i][j]=='B')
							{
								desx=i,desy=j;
							}
						}
					}
				}
			}
		}
		while(!cx.empty())
		{
			for(int k=0;k<8;k++)
			{
				int nx=cx.front()+vcx[k],ny=cy.front()+vcy[k];
				if(nx>=0 && nx<m && ny>=0 && ny<n && mapa[nx][ny]=='.')
				{
					mapa[nx][ny]='Z';
				}
			}
			cx.pop(),cy.pop();
		}
		beterBfs(orix,oriy,m,n,mapa,distv);
		if(distv[desx][desy].f==-1)
		{
			cout << "King Peter, you can't go now!\n";
		}
		else
		{
			cout << "Minimal possible length of a trip is " << distv[desx][desy].f << "\n";
		}
		
	}
}
