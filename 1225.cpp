#include <iostream>

using namespace std;

int main () {
	
	int t;
	cin >> t;
	for(int z=0;z<t;z++)
	{
		int vet[10]={0},n;
		cin >> n;
		for(int y=1;y<=n;y++)
		{
			int c=y,r;
			while(c!=0)
			{
				r=c%10;
				c=c/10;
				vet[r]++;
			}
		}
		for(int i=0;i<10;i++)
		{
			cout << vet[i];
			if(i<9)
			{
				cout << " ";
			}
		}
		cout << "\n";
	}
}
