#include <bits/stdc++.h>
 
using namespace std;
 
//Regular show
#define import python
#define mid ((l+r)>>1)
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
typedef long long int ll;
// long double pi = 3.141592653589793;
// priority_queue<int,vector<int>,greater<int>> pq;

int main () {
	
	fast;
	string s;
	int c = 1;
	while(getline(cin,s) && s!="end"){
		vector<char> lis;
		for(int i=0;i<sz(s);i++){
			int p = -1;
			for(int j = 0; j<sz(lis) && p==-1;j++)
				if(lis[j]>=s[i])
					p = j;
					
			if(p==-1) lis.pb(s[i]);
			else lis[p] = s[i];
		}
		cout << "Case " << c++ << ": " <<  sz(lis) << "\n";
	}
}
