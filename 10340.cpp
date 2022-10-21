#include <iostream>

using namespace std;

int solve(string a,string b){
	int j=0;
	int tam1 = a.size(),tam2 = b.size();
	for(int i=0;i<tam1;i++)
	{
		if(a[i]==b[j])
			j++;
		if(tam2 - j > tam1 - i+1 || j==tam2)
			i=tam1;
	}
	return j;
}

int main () {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string a,b;
	while(cin >> a >> b)
	{
		if((int)a.size()<(int)b.size()) swap(a,b);
		cout << ((solve(a,b)==(int)b.size()) ? "Yes\n" : "No\n");
	}
}
