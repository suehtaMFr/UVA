#include <iostream>
#include <cstring>

#define f first
#define s second

using namespace std;

char mapa[124][124];
int vx[4]={-1,0,1,0},vy[4]={0,1,0,-1};

/*d direção
* 0 cima
* 1 direita
* 2 baixo
* 3 esquerda
*/

int main () {
	
	int m,n,l;
	
	cin >> m >> n >> l;
	while(m || n || l)
	{
		pair<int,int> p;
		memset(mapa,' ',sizeof(mapa));
		int d;
		bool v=false;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin >> mapa[i][j];
				if(!v)
				{
					p={i,j};
					if(mapa[i][j]=='N')
					{
						d=0;
						v=true;
					}
					else
					{
						if(mapa[i][j]=='L')
						{
							d=1;
							v=true;
						}
						else
						{
							if(mapa[i][j]=='S')
							{
								d=2;
								v=true;
							}
							else
							{
								if(mapa[i][j]=='O')
								{
									d=3;
									v=true;
								}
							}
						}
					}
				}
			}
		}
		string fr;
		cin >> fr;
		int be=0;
		for(int y=0;y<l;y++)
		{
			if(fr[y]=='D')
			{
				d++;
				d=d%4;
			}
			else
			{
				if(fr[y]=='E')
				{	
					d=d+3;
					d=d%4;
				}
				else
				{
					int nx=p.f+vx[d],ny=p.s+vy[d];
					if(nx>=0 && nx <m && ny>=0 && ny<n && mapa[nx][ny]!='#')
					{
						if(mapa[nx][ny]=='*')
						{
							be++;
							mapa[nx][ny]='.';
						}
						p={nx,ny};
					}
				}
			}
		}
		cout << be << "\n";
		cin >> m >> n >> l;
	}	
}
