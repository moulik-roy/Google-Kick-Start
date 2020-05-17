#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int T, R, C, i, j, x, N, u, v;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>R>>C;
		string wall[R], y="";
		vector <int> graph[26], in_degree(26, 0), freq(26, 0);
		queue <int> q;
		for(i=0; i<R; i++)
			cin>>wall[i];
		for(i=0; i<R; i++){
			for(j=0; j<C; j++){
				freq[wall[i][j]-'A']++;
				if(i<R-1 && wall[i][j]!=wall[i+1][j]){
					graph[wall[i+1][j]-'A'].push_back(wall[i][j]-'A');
					in_degree[wall[i][j]-'A']++;
				}
			}
		}
		for(i=0, N=0; i<26; i++){
			if(freq[i]>0){
				N++;
				if(in_degree[i]==0)
					q.push(i);
			}
		}
		while(!q.empty()){
			u=q.front();
			y+=(char)(u+'A');
			for(i=0; i<graph[u].size(); i++){
				v=graph[u][i];
				in_degree[v]--;
				if(in_degree[v]==0)
					q.push(v);
			}
			q.pop();
		}
		if(y.length()<N)
			y="-1";
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}