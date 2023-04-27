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

string convert(string x){
	string z;
	for(int i=0;i<sz(x);i++)
		if(x[i]!=' ') z+=x[i];
	sort(all(z));
	return z;
}

int main () {
	
	fast;
	int tc;cin >> tc;
	while(tc--){
		vector<pair<string,string>> in;
		string s;
		while(s=="\0")
			getline(cin,s);
		while(s!="\0"){
			in.pb({s,convert(s)});
			getline(cin,s);
		}
		sort(all(in));
		vector<string> ans;
		for(int i=0;i<sz(in);i++){
			for(int j=i+1;j<sz(in);j++){
				if(in[i].ss==in[j].ss){
					ans.pb(in[i].ff + " = " + in[j].ff);
				}
			}
		}
		sort(all(ans));
		for(auto m:ans)
			cout << m << "\n";
		cout << (tc ? "\n" : "");
	}
}
