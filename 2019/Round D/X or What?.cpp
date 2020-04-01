#include <iostream>
#include <set>
using namespace std;

int main(){
	int T, N, Q, i, P, V, x, y, sum;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N>>Q;
		int A[N];
		set <int> positions;
		for(i=0, sum=0; i<N; i++){
			cin>>A[i];
			A[i]=__builtin_popcount(A[i]);
			sum=sum+A[i];
			if(A[i]%2!=0)
				positions.insert(i);
		}
		cout<<"Case #"<<x<<": ";
		while(Q--){
			cin>>P>>V;
			sum=sum-A[P];
			A[P]=__builtin_popcount(V);
			sum=sum+A[P];
			if(positions.find(P)!=positions.end())
				positions.erase(P);
			if(A[P]%2!=0)
				positions.insert(P);
			if(sum%2==0)
				y=N;
			else
				y=max(N-1-*positions.begin(), *positions.rbegin());
			cout<<y<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
