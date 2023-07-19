#include <bits/stdc++.h>
 
using namespace std;
 
//Regular show
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
	int tc; cin >> tc;
	while(tc--){
		int n, a, mx = INT_MIN, mn = INT_MIN; cin >> n >> a;
		for(int i = 0, x; i < a; i++){
			cin >> x;
			mx = max({mx,n-x,x});
			mn = max(mn,min(n-x,x));
		}
		cout << mn << " " << mx << "\n";
	}
}
