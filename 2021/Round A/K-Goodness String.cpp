#include <iostream>
using namespace std;

int main(){
	int T, N, K, i, x, y;
	string S;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N>>K;
		cin>>S;
		for(i=0, y=0; i<N/2; i++){
			if(S[i]!=S[N-1-i]){
				if(K>0)
					K--;
				else
					y++;
			}
		}
		y=max(y, K);
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}