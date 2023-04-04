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
	int n;
	while(cin >> n){
		vector<int> v(n);
		bool vis[1000002] = {0};
		for(int i=0;i<n;i++)
			cin >> v[i];
		sort(all(v));
		int d = INT_MAX, mn, s1, s2;
		cin >> mn;
		for(int i=0;i<n && v[i]<=mn;i++){
			if(vis[v[i]]) continue;
			int a = mn - v[i], b = lower_bound(all(v),a) - v.begin();
			vis[v[i]] = 1;
			if(v[b]!=a) continue;
			vis[v[b]] = 1;
			if(d > b-i)
				s1 = v[i],s2 = v[b],d = b - i;
		}
		cout << "Peter should buy books whose prices are " << s1 << " and " << s2 << ".\n\n";
	}
}
