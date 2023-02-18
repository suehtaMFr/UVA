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

string mat[26];
bool vis[26][26];
int vx[8] = {-1,-1,0,1,1,1,0,-1}, vy[8] = {0,1,1,1,0,-1,-1,-1};

void flod(int x,int y,int maxn){
	
	vis[x][y]=true;
	for(int k=0;k<8;k++){
		int nx = x+vx[k],ny = y+vy[k];
		if(nx>=0 && nx<maxn && ny>=0 && ny<maxn && !vis[nx][ny] && mat[nx][ny]=='1')
			flod(nx,ny,maxn);
	}
}

void ini(){
	
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			vis[i][j]=false;
		}
		mat[i]="";
	}
}

int main () {
	
	fast;
	int n,v=1;
	while(cin >> n)
	{
		ini();
		queue<pair<int,int>> q;
		for(int i=0;i<n;i++)
		{
			cin >> mat[i];
			for(int j=0;j<n;j++)
				if(mat[i][j]=='1') q.push({i,j});
		}
		int ans=0;
		while(!q.empty())
		{
			auto p = q.front();q.pop();
			if(!vis[p.ff][p.ss])
			{
				flod(p.ff,p.ss,n);
				ans++;
			}
		}
		cout << "Image number " << v++ << " contains " << ans << " war eagles.\n";
	}
}
