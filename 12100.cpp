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

int main () {
	
	fast;
	int tc; cin >> tc;
	while(tc--){
		int n, p, c=0, vl; cin >> n >> p;
		priority_queue<int> pq;
		queue<pair<int,int>> q;
		for(int i=0, x;i<n;i++){
			cin >> x;
			pq.push(x);
			q.push({x,i});
			if(p==i) vl=x;
		}
		bool ok = true;
		while(true){
			pair<int,int> t = q.front();q.pop();
			int x = pq.top();
			if(t.ff==x){
				c++;
				if(vl==x && t.ss==p){ ok = false; break;}
				if(vl==x) break;
				pq.pop();
			}
			else{
				q.push(t);
			}
		}
		while(ok && !q.empty()){
			pair<int,int> t = q.front();q.pop();
			if(t.ff==vl){
				c++;
				if(t.ss==p) break;
			}
			else q.push(t);
		}
		cout << c << "\n";
	}
}
