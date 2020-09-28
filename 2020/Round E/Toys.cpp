#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main(){
	long int T, N, i, x, y, z, sum, cur_time, count;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N;
		long int E[N], R[N];
		priority_queue <pair<long int, long int>> q;
		for(i=0, sum=0; i<N; i++){
			cin>>E[i]>>R[i];
			sum+=E[i];
		}
		for(i=0, cur_time=sum, z=sum, count=0, y=0; i<N; i++){
			cur_time+=E[i];
			q.push(make_pair(E[i]+R[i], i));
			while(!q.empty() && q.top().first>sum){
				cur_time-=(2*E[q.top().second]);
				sum-=E[q.top().second];
				count++;
				q.pop();
			}
			if(z<cur_time){
				y=count;
				z=cur_time;
			}
		}
		if(q.empty())
			cout<<"Case #"<<x<<": "<<y<<" "<<z<<"\n";
		else{
			y=count;
			cout<<"Case #"<<x<<": "<<y<<" INDEFINITELY\n";
		}
	}
	return 0;
}