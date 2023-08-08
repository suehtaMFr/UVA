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
	int tc;cin >> tc;
	string s,c;
	cin.ignore();
	while(tc--){
		getline(cin,s);
		stringstream a;a<<s;
		map<pair<string,string>,set<string>> mp;
		while(a>>s){
			c=s[0];c+=s.back();
			mp[{c,so(s)}].insert(s);
		}
		getline(cin,s);
		stringstream b;b<<s;
		vector<string> cp;
		while(b>>s) cp.pb(s);
		for(int i=0;i<sz(cp);i++){
			if(i) cout << " ";
			s=cp[i];
			c=s[0];c+=s.back();
			set<string> st = mp[{c,so(s)}];
			set<string>::iterator it;it=st.begin();
			if(sz(st)>=2) it++;
			cout << (((sz(st)>=1 && *st.begin()!=s) ? *st.begin() : ((sz(st)>=2&&*it!=s) ? *it : s)));
		}
		cout << "\n";
	}
}
