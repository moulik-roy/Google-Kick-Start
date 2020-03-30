#include <iostream>
#include <vector>
using namespace std;

int main(){
	int T, N, Q, L, R, i, j, x, y, odd_count;
	string S;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N>>Q;
		cin>>S;
		vector <vector<int>> dp(N+1, vector<int>(26, 0));
		for(i=0, y=0; i<N; i++){
			for(j=0; j<26; j++)
				dp[i+1][j]=dp[i][j];
			dp[i+1][S[i]-'A']++;
		}
		while(Q--){
			cin>>L>>R;
			for(i=0, odd_count=0; i<26; i++){
				if((dp[R][i]-dp[L-1][i])%2!=0)
					odd_count++;
			}
			if((R-L+1)%2==odd_count)
				y++;
		}
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}