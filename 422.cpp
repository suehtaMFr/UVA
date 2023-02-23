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

void find(int x,int y,int maxN,int d,string s,int p,pair<int,int> &pf, vector<string> &v){
	
	for(int k=0;k<8;k++)
	{
		int nx = x+vx[k], ny = y+vy[k];
		if(nx>=0 && nx<maxN && ny>=0 && ny <maxN && (d==-1||d==k) && s[p]==v[nx][ny])
		{
			if(p==sz(s)-1){
				pf = {nx,ny};
				return;
			}
			find(nx,ny,maxN,k,s,p+1,pf,v);
		}
	}
} 

int main () {
	
	
	int n;
	cin >> n;
	while(n){
		
		vector<string> v;
		pair<int,int> pi,pf;
		map<char,vector<pair<int,int>>> posi;
		string s;
		for(int i=0;i<n;i++)
		{
			cin >> s;
			v.pb(s);
			for(int j=0;j<n;j++)
				posi[v[i][j]].pb({i,j});
		}
		cin >> s;
		while(s[0]>57)
		{
			bool ans = false,ok;
			ok = posi.count(s[0]);
			for(int i=0;!ans && ok && i<sz(posi[s[0]]);i++)
			{
				pf = pi = posi[s[0]][i];
				find(pi.ff,pi.ss,n,-1,s,1,pf,v);
				ans = (pi != pf||sz(s)==1);
			}
			if(ans) cout << pi.ff+1 << "," << pi.ss+1 << " " << pf.ff+1 << "," <<pf.ss+1 << "\n";
			else cout << "Not found\n";
			cin >> s;
		}
		n = stoi(s);
	}
}
