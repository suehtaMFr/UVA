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

string so(string a){ sort(all(a));return a;}

int main () {
	
	fast;
	int tc, n;cin >> tc;
	string a, b;
	for(int z=0;z<tc;z++){
		if(z) cout << "\n";
		cin >> n;
		cin.ignore();
		string a, b;
		map<string,vector<string>> mp;
		for(int i=0;i<n;i++){
			getline(cin,a);
			b=so(a);
			mp[b].pb(a);
		}
		while(true){
			getline(cin,a);
			if(a=="END") break;
			b=so(a);
			cout << "Anagrams for: " << a << "\n";
			if(!sz(mp[b])) cout << "No anagrams for: " << a << "\n";
			else{
				int c=1;
				for(auto x : mp[b]){
					cout << "  " << c++ << ") " << x << "\n";
				}
			}
		}
	}
}
