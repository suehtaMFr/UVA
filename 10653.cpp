#include <iostream>
#include <queue>
#include <utility>

#define f first
#define s second

using namespace std;

bool matrix[1001][1001];

int bfs(int orix,int oriy,int destx,int desty,int maxX,int maxY){
	
	queue<pair<int,pair<int,int>>> fila;
	fila.push({orix,{oriy,0}});
	matrix[orix][oriy]=true;
	while(!fila.empty())
	{
		pair<int,pair<int,int>> par=fila.front();
		fila.pop();
		if(par.f==destx&&par.s.f==desty)//acabo
		{
			return par.s.s;
		}
		if(par.f-1>=0 && !matrix[par.f-1][par.s.f])
		{
			fila.push({par.f-1,{par.s.f,par.s.s+1}});
			matrix[par.f-1][par.s.f]=true;
		}
		if(par.s.f+1<maxY && !matrix[par.f][par.s.f+1])
		{
			fila.push({par.f,{par.s.f+1,par.s.s+1}});
			matrix[par.f][par.s.f+1]=true;
		}
		if(par.f+1<maxX && !matrix[par.f+1][par.s.f])
		{
			fila.push({par.f+1,{par.s.f,par.s.s+1}});
			matrix[par.f+1][par.s.f]=true;
		}
		if(par.s.f-1>=0 && !matrix[par.f][par.s.f-1])
		{
			fila.push({par.f,{par.s.f-1,par.s.s+1}});
			matrix[par.f][par.s.f-1]=true;
		}	
	}
	return 0;
}

int main () {
	
	int a,b;
	cin >> a >> b;
	while(a!=0||b!=0)
	{
		int qtb,i,j,posx,qnti,posy,ox,oy,dx,dy;
		cin >> qtb;
		for(i=0;i<qtb;i++){
			cin >> posx >> qnti;
			for(j=0;j<qnti;j++)
			{
				cin >> posy;
				matrix[posx][posy]=true;
			}
		}
		cin >> ox >> oy >> dx >> dy;
		cout << bfs(ox,oy,dx,dy,a,b) << "\n";
		for(i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				matrix[i][j]=false;
			}
		}
		cin >> a >> b;
	}
}
