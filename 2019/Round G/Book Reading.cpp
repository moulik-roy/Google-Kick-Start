#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
	long int T, N, M, Q, i, P, R, x, y;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N>>M>>Q;
		vector <long int> pages(N+1, 1);
		map <long int, long int> read;
		for(i=0, y=0; i<M; i++){
			cin>>P;
			pages[P]=0;
		}
		while(Q--){
			cin>>R;
			if(M!=N && read.find(R)==read.end()){
				for(i=R; i<=N; i+=R){
					if(pages[i]==1)
						read[R]++;
				}
			}
			y=y+read[R];
		}
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}