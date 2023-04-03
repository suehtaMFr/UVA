#include <bits/stdc++.h>
 
using namespace std;
 
//Regular show
#define mid ((l+r)>>1)
#define midf ((l+r)/2.0)
#define sz(x) ((long long int)x.size())
#define fin freopen ("input.txt","r",stdin);
#define fout freopen ("output.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
//rapadura é doce, mas não é mole não
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
//I see you
std::mt19937 rng((int) std::chrono ::steady_clock::now().time_since_epoch().count());
std::mt19937_64 rng64((int) std::chrono::steady_clock::now().time_since_epoch().count());
//~ long double pi = 3.141592653589793;

int dp[101][21][4001],m;

int f(int i,int j,int s,vector<vector<int>> &v){
	
	if(s>m) return -1;
	if(i==sz(v)) return s;
	if(j==sz(v[i])) return -1;
	if(dp[i][j][s] != -1) return dp[i][j][s];
	int op1 = f(i+1,  0,s+v[i][j],v);
	int op2 = f(  i,j+1,        s,v);
	return dp[i][j][s] = max(op1,op2);
}


int main () {
	
	fast;
	int tc;cin >> tc;
	while(tc--){
		int c;
		memset(dp,-1,sizeof(dp));
		cin >> m >> c;
		vector<vector<int>> v(c);
		string s;
		for(int i=0,x,y;i<c;i++){
			cin >> x;
			for(int j=0;j<x;j++){
				cin >> y;v[i].pb(y);
			}
		}
		int x =  f(0,0,0,v);
		cout << (x==-1 ? "no solution" : to_string(x)) << "\n";
	}
}
