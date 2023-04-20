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

int v[52];

int cal(string s){
    int x=0;
    for(int i=0;i<sz(s);i++)
        x += v[(s[i] - (s[i]<='Z' ? 39 : 97))];
    return x;
}

int main () {
	
	fast;
	for(int i=0;i<52;i++) v[i] = i+1;
	string s;
	while(cin >> s){
	    int x = cal(s);int y = sqrt(x);
	    bool ans = true;
	    for(int i=2;i<=y && ans;i++)
	        ans = x%i;
	    cout << (ans ? "It is a prime word.\n" : "It is not a prime word.\n");
	}
}
