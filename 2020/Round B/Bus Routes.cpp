#include <iostream>
using namespace std;

int main(){
	long int T, N, D, i, x, y, low, high, mid, end_day;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N>>D;
		long int X[N];
		for(i=0; i<N; i++)
			cin>>X[i];
		low=1;		high=D;
		while(low<high){
			mid=low+(high-low+1)/2;
			for(i=0, end_day=mid; i<N; i++){
				if(end_day%X[i]!=0)
					end_day+=(X[i]-(end_day%X[i]));
			}
			if(end_day<=D)
				low=mid;
			else
				high=mid-1;
		}
		y=low;
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}