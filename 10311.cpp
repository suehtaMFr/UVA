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

vector<int> v;
bool prime[10001] = {0};

bool ispr(int x){
	
	for(int i=0;i<sz(v) && v[i]*v[i]<=x;i++)
		if(!(x%v[i])) return false;
	return true;
}
	

int main () {
	
	fast;
	for(int i = 2; i <= 10000;i++){
		if(!prime[i]){
			v.pb(i);
			for(int j = i + i ;j <= 10000;j += i)
				prime[j] = true;
		}
	}
	int n;
	while(cin >> n && n ){
		if(n%2){
			if(n>3 && ispr(n-2)){
				cout << n << " is the sum of 2 and " << n-2 << ".\n";
			}
			else{
				cout << n << " is not the sum of two primes!\n";
			}
		}
		else{
			int l=-1,r=-1;
			for(int k = n/2;k<n && l==-1;k++){
				if(n-k>2 && k!=n-k && ispr(k) && ispr(n-k)){//goldbach
					l=k;
					r=n-k;
				}
			}
			if(l!=-1){
				cout << n << " is the sum of " << r << " and " << l << ".\n";
			}
			else{
				cout << n << " is not the sum of two primes!\n";
			}
		}
	}	
}
