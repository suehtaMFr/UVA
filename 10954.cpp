#include <iostream>
#include <queue>

using namespace std;

int main (){
	int n;
	while(cin >> n && n)
	{
		priority_queue<int , vector<int> , greater<int>> pq;
		int v;
		for(int i=0;i<n;i++)
		{
			cin >> v;
			pq.push(v);
		}
		long long int sum=0,cost=0;
		while(pq.size()>1)
		{
			sum=pq.top(),pq.pop();
			sum+=pq.top(),pq.pop();
			pq.push(sum);
			cost+=sum;
		}
		cout << cost << "\n";
	}	
}
