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

vector<int> v,t;
bool prime[18409501] = {0};
	
int main () {
	
	fast;
	for(int i = 2; i <= 18409500;i++){
		if(!prime[i]){
			v.pb(i);
			for(int j = i + i ;j <= 18409500;j += i)
				prime[j] = true;
		}
	}
	for(int i=0;i<sz(v)-1;i++){
		if(v[i]==v[i+1]-2){
			t.pb(v[i]);t.pb(v[i+1]);
		}
	}
	int n;
	while(cin >> n)
		cout << "(" << t[(2*n-2)] << ", " << t[(2*n-1)] << ")\n";
}
