#include <bits/stdc++.h>
 
using namespace std;
 
//Regular show
#define sz(x) ((int)x.size())
#define fin freopen ("a.txt","r",stdin);
#define fout freopen ("b.txt","w",stdout);
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
	vector<int> v;
	bool prime[1000001] = {0};
	set<int> st;
	for(int i = 2; i <= 1000000;i++){
		if(!prime[i]){
			v.pb(i);
			st.insert(i);
			for(int j = i + i ;j <= 1000000;j += i)
				prime[j] = true;
		}
	}
	int n;
	while(cin >> n && n){
		int p = 0, q = upper_bound(all(v),n) - v.begin()+1;
	    while(q && (p == 0 || n != p + v[q])){
	    	q--;
	    	p = (st.count(n - v[q]) ? n - v[q] : 0);
	    }
	    if(n == p + v[q]) cout << n << ":\n" << p << "+" << v[q] << "\n";
		else cout << n << ":\nNO WAY!\n"; 
	}
}
