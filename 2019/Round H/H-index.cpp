#include <iostream>
#include <vector>
using namespace std;

int main(){
	int T, N, i, A, x, y, count;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N;
		vector <int> citations(N+1, 0);
		cout<<"Case #"<<x<<": ";
		for(i=0, y=0, count=0; i<N; i++){
			cin>>A;
			if(A>y){
				if(A<=N)
					citations[A]++;
				else
					citations[N]++;
				if(citations[y]==count){
					y++;
					count=0;
				}
				else
					count++;
			}
			cout<<y<<" ";
		}
		cout<<"\n";
	}
	return 0;
}