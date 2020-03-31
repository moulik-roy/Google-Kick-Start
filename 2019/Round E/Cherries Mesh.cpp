#include <iostream>
using namespace std;

int findParent(int parent[], int u){
	while(parent[u]!=u){
		parent[u]=parent[parent[u]];
		u=parent[u];
	}
	return u;
}

int main(){
	int T, N, M, i, C, D, x, y;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N>>M;
		int parent[N+1];
		for(i=1, y=0; i<=N; i++)
			parent[i]=i;
		while(M--){
			cin>>C>>D;
			C=findParent(parent, C);
			D=findParent(parent, D);
			if(C!=D){
				y++;
				parent[D]=C;
			}
		}
		for(i=1, y=y-2; i<=N; i++){
			if(parent[i]==i)
				y+=2;
		}
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}