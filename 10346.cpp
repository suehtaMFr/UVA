#include <iostream>

using namespace std;

int main (){
	long long int b,qb;
	while(cin >> b >> qb)
	{
		long long int f=b;
		while(b>=qb)
		{
			f=f+(b/qb);
			b=(b/qb)+b%qb;
		}
		cout << f << "\n";
	}	
}
