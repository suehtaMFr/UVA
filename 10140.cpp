#include <bits/stdc++.h>
 
using namespace std;
 
//Regular show
#define sz(x) ((int)x.size())
#define fin freopen ("in.txt","r",stdin);
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

vector<int> v;
bool pr[100001] = {0};

bool prime(int x){
	
	for(int i=0;i<sz(v) && v[i]*v[i]<=x;i++)
		if(!(x%v[i])) return false;
	return true;
}

int cal(long long int l){
	int x = l%10,y = l%100,s = INT_MAX;
	int z=y/10;
	if(x<=3) s = abs(x - 3);
	if(x<=7) s = min(s,abs(x - 7));
	if(x<=9) s = min(s,abs(x - 9));
	return min(s,abs(y-z*10-1)); 	
}
	
int main () {
	
	fast;
	pr[1] = pr[0] = true;
	for(int i = 2; i <= 100000; i++){
		if(!pr[i]){
			v.pb(i);
			for(long long int j = (long long int)i * i ;j <= 100000;j += i)
				pr[j] = true;
		}
	}
	long long int l, r;
	while(cin >> l >> r){
		int at = 0,x1 = -1 , x2, y1, y2, mx = INT_MIN, mn = INT_MAX,z=-1;
		while(l<=r){
			if(l!=z){
				if(l<100001){
					if(!pr[l]){
						if(at){
							if(l-at>mx){
								mx = l-at;x1 = at;x2 = l;
							}
							if(l-at<mn){
								mn = l-at;y1 = at; y2 = l;
							}
						}
						at = l;
					}
				}
				else{
					if(prime(l)){
						if(at){
							if(l-at>mx){
								mx = l-at;x1 = at;x2 = l;
							}
							if(l-at<mn){
								mn = l-at;y1 = at; y2 = l;
							}
						}
						at = l;
					}
				}
			}
			z=l;
			l+=(l>9 ? cal(l) : 1);
			if(z==l)l+=cal(l+1)+1LL;
			
		}
		if(x1!=-1) cout << y1 << "," << y2 << " are closest, " << x1 << "," << x2 << " are most distant.\n";
		else cout << "There are no adjacent primes.\n";
	}
}
