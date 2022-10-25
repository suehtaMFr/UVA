#include <iostream>
#include <algorithm>

using namespace std;

long long int troca(long long int n){
	string a = to_string(n);
	reverse(a.begin(),a.end());
	return stoll(a);
}

int main () {
	
	int ct;
	cin >> ct;
	long long int n;
	for(int i=0;i<ct;i++)
	{
		int c=0;
		cin >> n;
		long long int r = troca(n);
		while(n!=r)
		{
			n+=r;
			r = troca(n);
			c++;
		}
		cout << c << " " << n << "\n";
	}
}
