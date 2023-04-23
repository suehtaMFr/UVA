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

bool veri(int i,vector<int> & t) { 
    if(i<0 || i>=sz(t)-2) return false;
    return (abs(t[i]-t[i+1])==abs(t[i+1]-t[i+2]));
}


int main () {
	
	fast;
	bool prime[100001] = {0};
	for(int i = 2; i <= 100000;i++){
		if(!prime[i]){
			for(int j = i + i ;j <= 100000;j += i)
				prime[j] = true;
		}
	}
    string s;
    while(cin >> s && s != "0"){
        int mx = INT_MIN;
        for(int i = 0;i < sz(s);i++){
            int v=0;
            for(int j = 0; j < 5;j++){
                v = v * 10 + (s[i+j]-48);
                if(!prime[v] && v > mx) mx = v;
            }
        }
        cout << mx << "\n";
    }
}
