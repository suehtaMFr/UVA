//save code

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
// long double pi = 3.141592653589793;

int main () {
	
	fast;
	string s;
	while(cin >> s && s!="#"){
		int v[26] = {0},ip = 0;
		for(int i=0;i<sz(s);i++) v[s[i]-97]++;
		for(int i=0;i<26;i++) ip += (v[i]%2);
		for(int i=0;i<26 && ip>1;i++)
			if(v[i]%2) cout << char(i+97),ip--;
		cout << "\n";
	}
}
