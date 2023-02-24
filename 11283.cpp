#include <bits/stdc++.h>

using namespace std;

//Regular show
#define mid ((l+r)>>1)
#define sz(x) ((long long int)x.size())
#define fin freopen ("input.txt","w",stdout);
#define fout freopen ("output.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//rapadura é doce, mas não é mole não
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
//I see you
//~ long double pi = 3.141592653589793;

int vx[8] = {-1,-1,0,1,1,1,0,-1}, vy[8] = {0,1,1,1,0,-1,-1,-1};
bool vis[10][10];

void find(int x,int y,string s,int p,bool &ans, vector<string> &v){
	
	for(int k=0;k<8;k++)
	{
		int nx = x+vx[k], ny = y+vy[k];
		if(nx>=0 && nx<4 && ny>=0 && ny <4 && !vis[nx][ny] && s[p]==v[nx][ny])
		{
			if(p==sz(s)-1){
				ans = true;
				return;
			}
			vis[nx][ny] = true;
			find(nx,ny,s,p+1,ans,v);
			vis[nx][ny] = false;
		}
	}
}

inline int point(int v){return (v<=2 ? 0 : v<=4 ? 1 : v==5 ? 2 : v==6 ? 3 : v==7 ? 5 : 11);}

int main () {
	
	fast;
	pair<int,int> u;
	int tc,n,t=1;
	string s;
	cin >> tc;
	while(tc--){
		
		vector<string> v;
		map<char,vector<pair<int,int>>> posi;
		for(int i=0;i<4;i++)
		{
			cin >> s;
			v.pb(s);
			for(int j=0;j<4;j++)
				posi[v[i][j]].pb({i,j});
		}
		cin >> n;
		long long int p = 0LL;
		bool ans;
		for(int i=0;i<n;i++)
		{
			cin >> s;
			ans = false;
			for(int j=0;!ans && j<sz(posi[s[0]]);j++)
			{
				u=posi[s[0]][j];
				vis[u.ff][u.ss]=true;
				find(u.ff,u.ss,s,1,ans,v);
				vis[u.ff][u.ss]=false;
			}
			p+=(ans ? point(sz(s)) : 0LL);
		}
		cout << "Score for Boggle game #" << t++ << ": " << p << "\n";
	}
}
