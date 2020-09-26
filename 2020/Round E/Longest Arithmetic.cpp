#include <iostream>
using namespace std;

int main(){
	int T, N, i, x, y, prev_diff, count;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N;
		int A[N];
		for(i=0; i<N; i++)
			cin>>A[i];
		for(i=2, prev_diff=A[1]-A[0], count=2, y=2; i<N; i++){
			if(A[i]-A[i-1]==prev_diff)
				count++;
			else{
				count=2;
				prev_diff=A[i]-A[i-1];
			}
			y=max(y, count);
		}
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}