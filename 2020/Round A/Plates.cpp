#include <iostream>
#include <vector>
using namespace std;

int main(){
	int T, N, K, P, i, j, k, x, y;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N>>K>>P;
		vector <vector<int>> beauty_value (N, vector<int>(K+1, 0)), dp(N+1, vector<int>(P+1, 0));
		for(i=0; i<N; i++){
			for(j=1; j<=K; j++){
				cin>>beauty_value[i][j];
				beauty_value[i][j]+=beauty_value[i][j-1];
			}
		}
		for(i=1; i<=N; i++){
			for(j=1; j<=P; j++){
				for(k=0; k<=K && k<=j; k++)
					dp[i][j]=max(dp[i][j], beauty_value[i-1][k]+dp[i-1][j-k]);
			}
		}
		y=dp[N][P];
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}