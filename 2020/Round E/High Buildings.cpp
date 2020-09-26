#include <iostream>
#include <vector>
using namespace std;

int main(){
	int T, N, A, B, C, i, x, hidden_buildings;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N>>A>>B>>C;
		vector <int> y;
		if(N==1 && A==1 && B==1 && C==1)
			y.push_back(1);
		else if(N==2){
			if(A==2 && B==2 && C==2){
				y.push_back(2);
				y.push_back(2);
			}
			else if(A==2 && B==1 && C==1){
				y.push_back(1);
				y.push_back(2);
			}
			else if(A==1 && B==2 && C==1){
				y.push_back(2);
				y.push_back(1);
			}
		}
		else if(N>2 && N-A-B+C>=0){
			hidden_buildings=N-(A+B-C);
			if(A-C>0){
				for(i=0; i<A-C; i++)
					y.push_back(2);
				for(i=0; i<hidden_buildings; i++)
					y.push_back(1);
				for(i=0; i<C; i++)
					y.push_back(3);
				for(i=0; i<B-C; i++)
					y.push_back(2);
			}
			else if(B-C>0){
				for(i=0; i<C; i++)
					y.push_back(3);
				for(i=0; i<hidden_buildings; i++)
					y.push_back(1);
				for(i=0; i<B-C; i++)
					y.push_back(2);
			}
			else if(C>1){
				y.push_back(3);
				for(i=0; i<hidden_buildings; i++)
					y.push_back(1);
				for(i=1; i<C; i++)
					y.push_back(3);
			}
		}
		cout<<"Case #"<<x<<": ";
		if(y.size()==0)
			cout<<"IMPOSSIBLE\n";
		else{
			for(i=0; i<N; i++)
				cout<<y[i]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}