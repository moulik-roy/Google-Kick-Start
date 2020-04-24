#include <iostream>
using namespace std;

int main(){
	long long int T, N, M, i, j, k, x, y, sum;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N>>M;
		long long int A[N], count[52]={0};
		for(i=0; i<N; i++)
			cin>>A[i];
		for(i=0, sum=0, k=0, y=-1; i<52; i++){
			for(j=0; j<N; j++){
				if((A[j]&(1LL<<i))!=0)
					count[i]++;
			}
			sum+=(1LL<<i)*min(count[i], N-count[i]);
			if(count[i]>=N-count[i])
				k|=(1LL<<i);
		}
		if(sum<=M){
			for(i=51; i>=0; i--){
				if((k&(1LL<<i))==0){
					sum-=(1LL<<i)*min(count[i], N-count[i]);
					sum+=(1LL<<i)*max(count[i], N-count[i]);
					if(sum<=M)
						k|=(1LL<<i);
					else{
						sum-=(1LL<<i)*max(count[i], N-count[i]);
						sum+=(1LL<<i)*min(count[i], N-count[i]);
					}
				}
			}
			y=k;
		}
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}