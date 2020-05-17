#include <iostream>
#include <vector>
using namespace std;

int main(){
	long int T, N, i, j, x, y, abs_sum, sum;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N;
		long int A[N];
		for(i=0, abs_sum=0; i<N; i++){
			cin>>A[i];
			abs_sum+=abs(A[i]);
		}
		vector <long int> dp(2*abs_sum+1, 0);
		for(i=0, sum=0, y=0, dp[abs_sum]=1; i<N; i++){
			sum+=A[i];
			for(j=0; j*j<=abs_sum+sum; j++)
				y+=dp[abs_sum+sum-j*j];
			dp[abs_sum+sum]++;
		}
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}