#include <iostream>
using namespace std;

struct node{
	long int sum, weighted_sum;
	
	node(){
		sum=0;
		weighted_sum=0;
	}
};

void updateBIT(node BIT[], long int N, long int index, long int sum, long int weighted_sum){
	while(index<=N){
		BIT[index].sum+=sum;
		BIT[index].weighted_sum+=weighted_sum;
		index+=(index&(-index));
	}
}

node getSum(node BIT[], long int index){
	node temp;
	while(index>0){
		temp.sum+=BIT[index].sum;
		temp.weighted_sum+=BIT[index].weighted_sum;
		index-=(index&(-index));
	}
	return temp;
}

int main(){
	long int T, N, Q, i, X, V, L, R, x, y, sweetness_score;
	char type;
	node prefix_L, prefix_R;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N>>Q;
		long int A[N];
		node BIT[N+1];
		for(i=0, y=0; i<N; i++){
			cin>>A[i];
			updateBIT(BIT, N, i+1, ((i%2==0)?A[i]:-A[i]), ((i%2==0)?A[i]:-A[i])*(i+1));
		}
		while(Q--){
			cin>>type;
			if(type=='U'){
				cin>>X>>V;
				updateBIT(BIT, N, X, ((X%2!=0)?1:-1)*(V-A[X-1]), ((X%2!=0)?X:-X)*(V-A[X-1]));
				A[X-1]=V;
			}
			else{
				cin>>L>>R;
				prefix_L=getSum(BIT, L-1);
				prefix_R=getSum(BIT, R);
				sweetness_score=(prefix_R.weighted_sum-prefix_L.weighted_sum)-(L-1)*(prefix_R.sum-prefix_L.sum);
				y+=((L%2!=0)?sweetness_score:-sweetness_score);
			}
		}
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}