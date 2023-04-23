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
	bool prime[65537] = {0};
	vector<int> v;
	for(int i = 2; i <= 65536;i++){
		if(!prime[i]){
		    v.pb(i);
			for(int j = i + i ;j <= 65536;j += i)
				prime[j] = true;
		}
	}
    long long int n,ax;
    while(cin >> n && n){
        ax = n,cout << n << " = ";
        vector<long long int> ans;
        if(n<0){ans.pb(-1);ax*=-1;}
        while(ax>1){
            int r = sqrt(ax);
            bool ok = false;
            for(int j = 0; j < sz(v) && r >= v[j] && !ok;j++){
                if(!(ax%v[j])){
                    ok = true;
                    ans.pb(v[j]);
                }
            }
            if(!ok) ans.pb(ax);
            ax /= ans.back();
        }
        for(int i=0;i<sz(ans);i++)
            cout << ans[i]  << (i+1==sz(ans) ? "\n" : " x ");
    }
}
