#include <iostream>
using namespace std;

int main(){
	long int T, N, i, j, x, y, sum;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N;
		long int C[N][N];
		for(i=0, y=0; i<N; i++){
			for(j=0; j<N; j++){
				cin>>C[i][j];
				if(i==j)
					y+=C[i][j];
			}
		}
		for(i=1; i<N; i++){
			for(j=0, sum=0; j+i<N; j++)
				sum+=C[j][j+i];
			y=max(y, sum);
			for(j=0, sum=0; j+i<N; j++)
				sum+=C[j+i][j];
			y=max(y, sum);
		}
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}