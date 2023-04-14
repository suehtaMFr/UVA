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

int main () {
	
	fast;
	int tc,n;cin >> tc;
	while(tc--){
		int s=0;
		cin >> n;
		vector<string> v(n+1),v2(n);v[0]="";
		for(int i=1;i<=n;i++)
			cin >> v[i];
		sort(all(v));
		for(int i=1,j;i<=n;i++){
			for(j=0;j<min(sz(v[i-1]),sz(v[i])) && v[i-1][j]==v[i][j];j++);
			s+=(sz(v[i])-j);
		}
		cout << s << "\n";
		for(int i=1;i<=n;i++)
			cout << v[i] << "\n";
	}
}
