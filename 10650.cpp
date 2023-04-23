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
	vector<int> v,t;
	bool prime[32001] = {0};
	for(int i = 2; i <= 32000;i++){
		if(!prime[i]){
			v.pb(i);
			for(int j = i + i ;j <= 32000;j += i)
				prime[j] = true;
		}
	}
	for(int i=0;i<sz(v);i++){
		int k=0;
		bool ok = true;
		for(int j=i,ab=-1;j<sz(v)-1 && ok;j++){
			if(ab==-1 || abs(v[j]-v[j+1])==ab){
				ab=abs(v[j]-v[j+1]);
				k++;
				ok = true;
			}
			else ok = false;
		}
		if(k>=2){
			for(int j=i;j<=i+k;j++) t.pb(v[j]);
			i+=(k==3);
		}
	}
	int x, y;
	while(cin >> x >> y && (x || y)){
		if(x>y) swap(x,y);
		int i = lower_bound(all(t),x) - t.begin();
		int j = lower_bound(all(t),y) - t.begin(),ab,k,z;j -= (t[j]>y);
	    if(veri(i-1,t) && veri(i,t)) i+=3;
	    for(;i<=j-2;i++){
	        if(veri(i,t) && ((i<=j-3 && veri(i+1,t)) || !veri(i+1,t))){
                for(int k=0;k<3;k++)
                    cout << (k ? " " : "") << t[i+k];
                if(i<=j-3 && veri(i+1,t)){
                    cout << " " << t[i+3];i++;
	            }
                cout << "\n";
                i+=2;
	        }
	    }
	}
}
