#include <iostream>
#include <vector>
using namespace std;

void dfs(vector <long int> tree[], long int u, vector <long int> &ancestors, long int A, long int B, vector <vector<long int>> &dp){
	ancestors.push_back(u);
	for(long int i=0; i<tree[u].size(); i++)
		dfs(tree, tree[u][i], ancestors, A, B, dp);
	ancestors.pop_back();
	if(ancestors.size()>=A)
		dp[ancestors[ancestors.size()-A]][0]+=dp[u][0];
	if(ancestors.size()>=B)
		dp[ancestors[ancestors.size()-B]][1]+=dp[u][1];
}

int main(){
	long int T, N, A, B, i, x, parent;
	double y;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N>>A>>B;
		vector <long int> tree[N+1], ancestors;
		vector <vector<long int>> dp(N+1, vector<long int>(2, 1));
		for(i=1; i<N; i++){
			cin>>parent;
			tree[parent].push_back(i+1);
		}
		dfs(tree, 1, ancestors, A, B, dp);
		for(i=1, y=0; i<=N; i++)
			y+=(N*(dp[i][0]+dp[i][1])-dp[i][0]*dp[i][1]);
		y/=(N*N);
		printf("Case #%ld: %.6lf\n", x, y);
	}
	return 0;
}