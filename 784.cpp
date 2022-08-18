#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define pb push_back

int vx[4]={-1,1,1,0},vy[4]={0,1,0,-1};
bool vis[34][84];

void flodflil(int x,int y,int maxX,int maxY,vector<string>& mapa){
	
	vis[x][y]=true;
	mapa[x][y]='#';
	for(int k=0;k<4;k++)
	{
		int nx=x+vx[k],ny=y+vy[k];
		if(nx>=0 && nx<maxX && ny>=0 && ny<maxY && !vis[nx][ny] && mapa[nx][ny]==' ')
		{
			flodflil(nx,ny,maxX,maxY,mapa);
		}
	}
}

bool verify(string s){
	bool res=true;
	int t = s.size();  
	for(int i=0;i<t && res;i++)
	{
		if(s[i]!='_')
		{
			res=false;
		}
	}
	return res;
}

int main() {

	int ct;
	cin >> ct;
	cin.ignore();
	for(int z=0;z<ct;z++)
	{
		memset(vis,false,sizeof(vis));
		vector<string> mapa;
		string f;
		getline(cin,f);
		int mtf=-1;
		while(true)
		{
			int tf=f.size();
			if(tf>mtf)mtf=tf;
			mapa.pb(f);
			if(verify(f)) break;
			getline(cin,f);
		}
		int t = mapa.size(),ox,oy;
		for(int z=0;z<t;z++)
		{
			int t2 = mapa[z].size();
			for(int y=0;y<t2;y++)
			{
				if(mapa[z][y]=='X')
				{
					vis[z][y]=true;
				}
				else
				{
					if(mapa[z][y]=='*')
					{
						ox=z,oy=y;
					}
				}
			}
			if(t2<mtf)
			{
				for(int y=t2;y<mtf;y++)
				{
					mapa[z]+='x';
					vis[z][y]=true;
				}
			}
		}
		flodflil(ox,oy,t,mtf,mapa);
		for(int i=0;i<t;i++)
		{
			for(int j=0;j<mtf;j++)
			{
				if(mapa[i][j]!='x')
				{
					cout << mapa[i][j];
				}
			}
			cout << "\n";
		}
	}
} 
