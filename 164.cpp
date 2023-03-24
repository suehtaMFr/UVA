#include <bits/stdc++.h>
 
using namespace std;
 
//Regular show
#define mid ((l+r)>>1)
#define midf ((l+r)/2.0)
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
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
std::mt19937_64 rng64((int) std::chrono::steady_clock::now().time_since_epoch().count());
//~ long double pi = 3.141592653589793;
#define pfc(x) {cout << x;continue;}

int dp[21][21];
int f(int i,int j,string a,string b){
	if(i==sz(a)) return dp[i][j] = sz(b)-j;
	if(j==sz(b)) return dp[i][j] = sz(a)-i;
	if(dp[i][j]!=-1) return dp[i][j];
	if(a[i]==b[j]) return dp[i][j] = f(i+1,j+1,a,b);//DEU GOOD
	int op1 = f(i,j+1,a,b);//include
	int op2 = f(i+1,j,a,b);//delete
	int op3 = f(i+1,j+1,a,b);//swap
	return dp[i][j] = min({op1,op2,op3})+1;
}

void recover(int i, int j, string a, string b,int paia) {//paia == offset abre "bem broxa"
	if(i == sz(a) && j == sz(b)) return;
	
	if(i==sz(a)){
		cout << "I" << b[j] << (i+1+paia<=9 ? "0":"") << i+1+paia;
		recover(i,j+1,a,b,paia+1);
		return;
	}
	if(j==sz(b)){
		cout << "D" << a[i] << (i+1+paia<=9 ? "0":"") << i+1+paia;
		recover(i+1,j,a,b,paia-1);
		return;
	}
	
	if(a[i]==b[j]){ recover(i+1,j+1,a,b,paia); return;}
	
	if(dp[i][j] == 1 + f(i, j + 1, a, b)){
		cout << "I" << b[j] << (i+1+paia<=9 ? "0":"") << i+1+paia;
		recover(i,j+1,a,b,paia+1);
		return;
	}
	if(dp[i][j] == 1 + f(i + 1, j, a, b)){
		cout << "D" << a[i] << (i+1+paia<=9 ? "0":"") << i+1+paia;
		recover(i+1,j,a,b,paia-1);
		return;
	}
	if(dp[i][j] == 1 + f(i + 1, j + 1, a, b)){
		cout << "C" << b[j] << (i+1+paia<=9 ? "0":"") << i+1+paia;
		recover(i+1,j+1,a,b,paia);
		return;
	}
}

int main () {
	
	fast;
	string a,b;
	while(cin >> a && a!="#"){
		cin >> b;
		memset(dp,-1,sizeof(dp));
		f(0,0,a,b);
		recover(0,0,a,b,0);
		cout << "E\n";
	}
}
