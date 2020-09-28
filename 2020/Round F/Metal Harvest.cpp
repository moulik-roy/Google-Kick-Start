#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main(){
	int T, N, K, i, S, E, x, y, end, count;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N>>K;
		vector <pair<int, int>> intervals;
		for(i=1; i<=N; i++){
			cin>>S>>E;
			intervals.push_back(make_pair(S, E));
		}
		sort(intervals.begin(), intervals.end());
		for(i=0, end=0, y=0; i<N; i++){
			S=intervals[i].first;
			E=intervals[i].second;
			if(end<E){
				end=max(end, S);
				count=(E-end+K-1)/K;
				end+=(count*K);
				y+=count;	
			}
		}
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}