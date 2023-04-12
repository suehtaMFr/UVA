#include <bits/stdc++.h>
 
using namespace std;
 
//Regular show
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
std::mt19937 rng((int) std::chrono ::steady_clock::now().time_since_epoch().count());
std::mt19937_64 rng64((int) std::chrono::steady_clock::now().time_since_epoch().count());
//~ long double pi = 3.141592653589793;

int main () {
	
	fast;
	int n;
	while(cin >> n && n){
		
		stack<pair<int,int>> by,sd;
		pair<int,int> ax;
		long long int s=0LL; 
		for(int i=0,x;i<n;i++){
			cin >> x;
			if(!x) continue;
			if(x>0){
				
				if(sd.empty()){
					by.push({x,i});
				}
				else{
					while(!sd.empty() && x>0){
						ax = sd.top();sd.pop();
						if(-1*ax.ff==x){
							s+= x*(i-ax.ss);
							x=0;
						}
						else{
							if(-1*ax.ff>x){
								s+= x*(i-ax.ss);
								ax.ff+=x;
								x=0;
								sd.push(ax);
							}
							else
							{
								s+= (-1*ax.ff)*(i-ax.ss);
								x+=ax.ff;
								if(sd.empty()) by.push({x,i});
							}
						}
					}
				}
			}
			else{
				if(by.empty()){
					sd.push({x,i});
				}
				else{
					while(!by.empty() && x<0){
						ax = by.top();by.pop();
						if(ax.ff==-1*x){
							s+= ax.ff*(i-ax.ss);
							x=0;
						}
						else{
							if(ax.ff>-1*x){
								s+= (-1*x)*(i-ax.ss);
								ax.ff+=x;
								x=0;
								by.push(ax);
							}
							else
							{
								s+= ax.ff*(i-ax.ss);
								x+=ax.ff;
								if(by.empty()) sd.push({x,i});
							}
						}
					}
				}
			}
		}
		cout << s << "\n";
	}
}
