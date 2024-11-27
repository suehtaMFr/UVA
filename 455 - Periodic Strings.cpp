#include <bits/stdc++.h>

using namespace std;

// Regular show
#define import python
#define mid ((l+r)>>1)
#define sz(x) ((int)x.size())
#define fin freopen ("in.txt","r",stdin);
#define fout freopen ("out.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
// Rapadura é doce, mas não é mole não.
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
// I see you
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vll;
// priority_queue<int,vector<int>,greater<int>> pq;

vi kmp_function(string const& S) {
  int N = sz(S);
  vi pi(N, 0);
  for (int i = 1; i < N; i++) {
    int j = pi[i-1];
    while (j > 0 && S[i] != S[j]) j = pi[j-1];
    if (S[i] == S[j]) j++;
    pi[i] = j;
  }
  return pi;
}

vi z_function(string const& S) {
  int N = sz(S);
  vi z(N);
  int l = 0, r = 0;
  for (int i = 1; i < N; i++) {
    if (i < r) z[i] = min(r-i, z[i-l]);
    while (i + z[i] < N && S[z[i]] == S[i+z[i]]) z[i]++;
    if (i + z[i] > r) l = i, r = i+z[i];
  }
  return z;
}

int main(){
  fast;
  int tc; cin >> tc;
  while(tc--){
    string s, ax, c; cin >> s;
    vi a, b;
    a = kmp_function(s);
    b = z_function(s);
    int mx = -1;
    for(int i=0;i<sz(s);i++) mx = max(mx, a[i]);
    for(int i=0;i<sz(s) && b[i]!=mx;i++) ax+=s[i];
    for(int i=0;sz(ax) && i<sz(s)/sz(ax);i++) c+=ax;
    if(!mx || c!=s) ax=s;
    cout << sz(ax) << "\n";
    if(tc) cout << "\n";
  }
}
