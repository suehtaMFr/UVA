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

int main () {
	
	fast;
	int n,q,v=1;
	while(cin >> n >> q && (n || q)){
		cout << "CASE# "<< v++ << ":\n";
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin >> v[i];
		sort(all(v));
		for(int i=0,x;i<q;i++){			
			cin >> x;
			int a = lower_bound(all(v),x)-v.begin();
			if(v[a]==x)
				cout << x << " found at " << a+1 << "\n";
			else 
				cout << x << " not found\n";
		}
	}
}
