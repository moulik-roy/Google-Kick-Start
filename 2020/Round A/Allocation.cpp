#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int T, N, B, i, x, y;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N>>B;
		int A[N];
		for(i=0; i<N; i++)
			cin>>A[i];
		sort(A, A+N);
		for(i=0; i<N && B-A[i]>=0; i++)
			B=B-A[i];
		y=i;
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}
