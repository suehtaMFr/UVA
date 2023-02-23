#include <bits/stdc++.h>
 
using namespace std;
 
//Regular show
#define mid ((l+r)>>1)
#define sz(x) ((long long int)x.size())
#define fin freopen ("input.txt","r",stdin);
#define fout freopen ("output.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//rapadura é doce, mas não é mole não
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
//I see you
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
std::mt19937_64 rng64((int) std::chrono::steady_clock::now().time_since_epoch().count());
//~ long double pi = 3.141592653589793;

char mapa[124][124];
int vx[4]={-1,0,1,0},vy[4]={0,1,0,-1};

/*d direction
* 0 north
* 1 East
* 2 south
* 3 west
*/

int main () {
	
	fast;
	int m,n,l;
	cin >> m >> n >> l;
	while(m || n || l)
	{
		pair<int,int> p;
		memset(mapa,' ',sizeof(mapa));
		int d=-1;
		bool v=false;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin >> mapa[i][j];
				if(!v)
				{
					p={i,j};
					d = (mapa[i][j]=='N' ? 0 : mapa[i][j]=='L' ? 1 : mapa[i][j]=='S' ? 2 : mapa[i][j]=='O' ? 3 : -1 );
					v = (d!=-1);
				}
			}
		}
		string fr;
		cin >> fr;
		int be=0;
		for(int y=0;y<l;y++)
		{
			if(fr[y]=='D') d=(d+1)%4;
			else if(fr[y]=='E')	d=(d+3)%4;
			else
			{
				int nx=p.ff+vx[d],ny=p.ss+vy[d];
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
		cout << be << "\n";
		cin >> m >> n >> l;
	}	
}
