#include <iostream>
using namespace std;

int main(){
	int T, N, K, i, x, y, low, high, mid, count;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N>>K;
		int M[N];
		for(i=0; i<N; i++)
			cin>>M[i];
		low=1;	high=1000000000;
		while(low<high){
			mid=low+(high-low)/2;
			for(i=1, count=0; i<N && count<=K; i++){
				if(M[i]-M[i-1]>mid)
					count=count+((M[i]-M[i-1]-1)/mid);
			}
			if(count<=K)
				high=mid;
			else
				low=mid+1;
		}
		y=low;
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}