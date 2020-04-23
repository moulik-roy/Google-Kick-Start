#include <iostream>
using namespace std;

int main(){
	int T, N, i, x, y;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N;
		int H[N];
		for(i=0; i<N; i++)
			cin>>H[i];
		for(i=1, y=0; i<N-1; i++){
			if(H[i-1]<H[i] && H[i]>H[i+1])
				y++;
		}
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}