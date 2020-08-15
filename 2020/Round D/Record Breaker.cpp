#include <iostream>
using namespace std;

int main(){
	int T, N, i, x, y, max_visitors;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N;
		int V[N];
		for(i=0; i<N; i++)
			cin>>V[i];
		for(i=0, max_visitors=-1, y=0; i<N; i++){
			if(max_visitors<V[i]){
				max_visitors=V[i];
				if(i==N-1 || (i<N-1 && max_visitors>V[i+1]))
					y++;
			}
		}
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}
