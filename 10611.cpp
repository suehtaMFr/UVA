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
	int n,q;cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin >> v[i];
	cin >> q;
	for(int i=0,x;i<q;i++){
		cin >> x;
		int a = lower_bound(all(v),x)-v.begin()-1;
		int b = upper_bound(all(v),x)-v.begin();
		if(a<0 ||v[a]>=x) cout << "X ";
		else cout << v[a] << " ";
		if(b>=n || v[b]<=x) cout << "X\n";
		else cout << v[b] << "\n";
	}
}
