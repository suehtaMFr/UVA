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
typedef long long int ll;

bool prime(long long int x){
    for(int i = 2, r = sqrt(x); i <= r;i++)
        if(!(x%i)) return false;
    return true;
}

int main () {
	
	fast;
    long long int n;
    while(cin >> n && n){
        long long int mx = INT_MIN;
        int pr = 0;
        n *= (n<0 ? -1 : 1); 
        for(int i = 2,r = sqrt(n) + 1; i <= r;i++){
            if(!(n%i) && n!=i){
                if(i*i==n && prime((ll)i))
                    mx = max(mx,(ll)i),pr++;
                else{
                    if(prime((ll)i))
                        mx = max(mx,(ll)i),pr++;
                    if(prime((ll)n/i)) 
                        mx = max(mx,(ll)n/i),pr++;
                }
            }
        }
        cout << (pr>=2 ? mx : -1LL) << "\n";
    }
}
