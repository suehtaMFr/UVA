#include <bits/stdc++.h>
 
using namespace std;
 
//Regular show
#define mid ((l+r)>>1)
#define sz(x) ((int)x.size())
#define fin (freopen ("input.txt","r",stdin))
#define fout (freopen ("output.txt","w",stdout))
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
	int tc;cin >> tc;
	while(tc--){
		string s,x,ex[24];
		cin >> s;
		int j=0;
		for(int i=0;i<sz(s);i++){
			if(s[i]>=48) x+=s[i];
			else{
				ex[j++]=x;x="";
				ex[j++]=s[i];
			}
		}
		ex[j++]=x;
		stack<long long> mt,sm;
		long long ax;
		for(int i=1;i<j;i+=2){
			if(i==1){
				if(ex[i]=="+") sm.push(stoll(ex[i-1]));
				else mt.push(stoll(ex[i-1]));
			}
			if(ex[i]=="+"){
				sm.push(stoll(ex[i+1]));
				if(mt.empty()){
					mt.push(stoll(ex[i-1])+stoll(ex[i+1]));
				}
				else{
					ax = mt.top();mt.pop();
					mt.push(ax+stoll(ex[i+1]));
				}
			}
			else
			{
				mt.push(stoll(ex[i+1]));
				if(sm.empty()){
					sm.push(stoll(ex[i-1])*stoll(ex[i+1]));
				}
				else{
					ax = sm.top();sm.pop();
					sm.push(ax*stoll(ex[i+1]));
				}
			}
		}
		long long mi=0,mx=1;
		while(!sm.empty()){
			mi+=sm.top();sm.pop();
		}
		while(!mt.empty()){
			mx*=mt.top();mt.pop();
		}
		if(j==1) mi = mx = stoll(ex[0]);
		cout << "The maximum and minimum are " << mx << " and " << mi << ".\n";
	}
}
