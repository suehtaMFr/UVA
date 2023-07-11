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

string fix(string s){
	string r;
	int v[26] = {0};
	for(int i=0;i<sz(s);i++) v[s[i]-97]++;
	for(int i=0;i<26;i++)
		for(int j=0;j<v[i];j++)
			r+=(i+97);
	return r;
}

int main () {
	
	fast;
	int tc; cin >> tc;
	cin.ignore();
	string s,s1;
	while(tc--){
		map<string,string> mp;
		getline(cin,s);
		getline(cin,s1);
		stringstream a;
		a << s;
		while(a>>s){
			string x = fix(s);
			if(!mp.count(x))mp[fix(s)]=s;
		}
		stringstream b;
		b << s1;
		int v=0;
		while(b>>s1){
			if(v++)cout << " ";
			string x = fix(s1);
			cout << (mp.count(x) ? mp[x] : s1);	
		}
		cout << "\n";
	}
}
