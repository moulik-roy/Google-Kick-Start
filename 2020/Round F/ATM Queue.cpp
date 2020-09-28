#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main(){
	int T, N, X, i, A, x;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N>>X;
		vector <pair<int, int>> y;
		for(i=1; i<=N; i++){
			cin>>A;
			y.push_back(make_pair((A+X-1)/X, i));
		}
		sort(y.begin(), y.end());
		cout<<"Case #"<<x<<": ";
		for(i=0; i<N; i++)
			cout<<y[i].second<<" ";
		cout<<"\n";
	}
	return 0;
}