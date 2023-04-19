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
	vector<int> v = {1};
	bool prime[1001] = {0};
	
	for(int i = 2; i <= 1000;i++){
		if(!prime[i]){
			v.pb(i);
			for(int j = i + i ;j <= 1000;j += i)
				prime[j] = true;
		}
	}
	int n, c;
	
	while(cin >> n >> c){
		int id = upper_bound(all(v),n) - v.begin() - 1;
		cout << n << " " << c << ": ";
		if((id+1)%2){
			int mid = id/2,d = c-1;
			if((2*c)-1>=id+1){
				for(int i = 0;i<=id;i++)
					cout << v[i] << " \n"[i==id];
			}
			else
			{
				for(int i = mid-d;i<=mid+d;i++)
					cout << v[i] << " \n"[i==mid+d];
			}
		}
		else{
			int d = (id + 1 - 2*c)/2;
			if(2*c>=id+1){
				for(int i = 0;i<=id;i++)
					cout << v[i] << " \n"[i==id];
			}
			else{
				for(int i=0 + d;i<=id-d;i++)
					cout << v[i] << " \n"[i==id-d];
			}
		}
		cout << "\n";
	}
}
