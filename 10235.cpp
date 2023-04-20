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
	bool prime[1000001] = {0};
	for(int i = 2; i <= 1000000;i++){
		if(!prime[i]){
			for(int j = i + i ;j <= 1000000;j += i)
				prime[j] = true;
		}
	}
	int n;
	while(cin >> n){
	    if(!prime[n]){
	        string b = to_string(n),c; c = b; reverse(all(b));
	        if(c!=b && !prime[stoi(b)]) cout << n << " is emirp.\n";
	        else cout << n << " is prime.\n";
	    }
	    else cout << n << " is not prime.\n";
	}
}
