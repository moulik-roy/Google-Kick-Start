#include <iostream>
using namespace std;

int main(){
	int T, K, i, x, y, low, high;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>K;
		int A[K];
		for(i=0; i<K; i++)
			cin>>A[i];
		for(i=1, low=0, high=0, y=0; i<K; i++){
			if(A[i-1]>A[i]){
				low++;
				high=0;
			}
			else if(A[i-1]<A[i]){
				high++;
				low=0;
			}
			if(low==4 || high==4){
				y++;
				low=0;
				high=0;
			}
		}
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}