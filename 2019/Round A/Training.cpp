#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int T, N, P, i, x, y, sum;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N>>P;
		int S[N];
		for(i=0; i<N; i++)
			cin>>S[i];
		sort(S, S+N);
		for(i=0, sum=0; i<P; i++)
			sum=sum+S[i];
		for(i=P, y=P*S[P-1]-sum; i<N; i++){
			sum=sum+S[i]-S[i-P];
			y=min(y, P*S[i]-sum);
		}
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}