#include <bits/stdc++.h>
 
using namespace std;
 
//Regular show
#define mid ((l+r)>>1)
#define sz(x) ((int)x.size())
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

/*
101
010
101

-1,1,1,-1
1,1,-1,-1

-1, 0, 1, 0
 0, 1, 0,-1
*/

int n;

bool veri(int x,int y,char c,vector<string> &v){
	return (((x-1<0)  || (x-1>=0 && v[x-1][y]!=c)) && ((y+1>=n) || (y+1<n && v[x][y+1]!=c))  && ((x+1>=n) || (x+1<n && v[x+1][y]!=c))  && ((y-1<0)  || (y-1>=0 && v[x][y-1]!=c)));
}

int main () {
	
	fast;
	int tc;cin >> tc;
	for(int z=1;z<=tc;z++){
		cin >> n;
		vector<string> v(n);
		for(int i=0;i<n;i++)
			cin >> v[i];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(v[i][j]=='.'){
					for(char c = 'A';c <= 'Z' && v[i][j]=='.';c++)
						if(veri(i,j,c,v)) v[i][j]=c;
				}
			}
		}
		cout << "Case " << z << ":\n";
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cout << v[i][j] << (j+1!=n ? "":"\n");
	}
}
