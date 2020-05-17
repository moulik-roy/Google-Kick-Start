#include <iostream>
using namespace std;

int main(){
	int T, N, K, i, A, x, y, countdown;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N>>K;
		for(i=0, countdown=K, y=0; i<N; i++){
			cin>>A;
			if(A!=countdown)
				countdown=K;
			if(A==countdown){
				countdown--;
				if(countdown==0){
					countdown=K;
					y++;
				}
			}
		}
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}