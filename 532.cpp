#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>

#define pb push_back
#define f first
#define s second

using namespace std;

int vz[6]={0,0,0,0,1,-1},vx[6]={-1,0,1,0,0,0},vy[6]={0,1,0,-1,0,0};
vector<vector<vector<char>>> mapa (34);
vector<vector<vector<pair<int,bool>>>> vd(34);

int bfs3D(int ori[],int des[],int maxZ,int maxX,int maxY){
	
	vd[ori[0]][ori[1]][ori[2]].f=0;
	vd[ori[0]][ori[1]][ori[2]].s=false;
	queue<pair<int,pair<int,int>>> f;
	f.push({ori[0],{ori[1],ori[2]}});
	while(!f.empty())
	{
		pair<int,pair<int,int>> u=f.front();
		f.pop();
		if(u.f==des[0] && u.s.f==des[1] && u.s.s==des[2])
		{
			return vd[u.f][u.s.f][u.s.s].f;
		}
		for(int k=0;k<6;k++)
		{
			int nz=u.f+vz[k],nx=u.s.f+vx[k],ny=u.s.s+vy[k];
			if(nz>=0 && nz<maxZ && nx>=0 && nx <maxX && ny>=0 && ny <maxY && !vd[nz][nx][ny].s 
			&& (mapa[nz][nx][ny]=='.'|| mapa[nz][nx][ny]=='S'))
			{
				vd[nz][nx][ny].f=vd[u.f][u.s.f][u.s.s].f+1;
				vd[nz][nx][ny].s=true;
				mapa[nz][nx][ny]='V';
				f.push({nz,{nx,ny}});
			}
		}
	}
	return -1;
}

int main () {
	
	int l,m,n;
	cin >> l >> m >> n;
	
	while(l||m||n)
	{
		for(int z=0;z<31;z++)
		{
			vector<vector<char>> auxm2;
			vector<vector<pair<int,bool>>> auxv2;
			for(int y=0;y<31;y++)
			{
				vector<char> auxm;
				vector<pair<int,bool>> auxv;
				for(int x=0;x<31;x++)
				{
					auxm.pb('a');
					auxv.pb({-1,false});
				}
				auxm2.pb(auxm);
				auxv2.pb(auxv);
			}
			mapa[z]=auxm2;
			vd[z]=auxv2;
		}
		char c;
		int ori[3],des[3];
		for(int z=0;z<l;z++)
		{
			for(int x=0;x<m;x++)
			{
				for(int y=0;y<n;y++)
				{
					cin >> c;
					mapa[z][x][y]=c;
					if(c=='#')
					{
						vd[z][x][y].s=true;
					}
					else
					{
						if(c=='E')
						{
							ori[0]=z,ori[1]=x,ori[2]=y;
						}
						else
						{
							if(c=='S')
							{
								des[0]=z,des[1]=x,des[2]=y;
							}
						}
					}
				}
			}
			string linha;
			cin.ignore();
			getline(cin,linha);
		}
		int d;
		d=bfs3D(ori,des,l,m,n);
		if(d==-1)
		{
			cout << "Trapped!\n";
		}
		else
		{
			cout << "Escaped in "<< d << " minute(s).\n";
		}
		for(int z=0;z<l;z++)
		{
			mapa[z].clear();
			vd[z].clear();
		}
		cin >> l >> m >> n;
	}
}
