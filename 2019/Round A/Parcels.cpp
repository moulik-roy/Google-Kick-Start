#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector <vector<int>> bfs(string grid[], int R, int C){
	int i, j, r1, c1, r2, c2, dr[4]={0, 1, 0, -1}, dc[4]={1, 0, -1, 0};
	vector <vector<int>> dist(R, vector<int>(C, -1));
	queue <pair<int, int>> q;
	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			if(grid[i][j]=='1'){
				dist[i][j]=0;
				q.push(make_pair(i, j));
			}
		}
	}
	while(!q.empty()){
		r1=q.front().first;
		c1=q.front().second;
		for(i=0; i<4; i++){
			r2=r1+dr[i];
			c2=c1+dc[i];
			if(r2>=0 && r2<R && c2>=0 && c2<C && dist[r2][c2]==-1){
				dist[r2][c2]=dist[r1][c1]+1;
				q.push(make_pair(r2, c2));
			}
		}
		q.pop();
	}
	return dist;
}

bool binary_search(vector <vector<int>> &dist, int D){
	int i, j, R, C, flag, sum, diff, min_sum, max_sum, min_diff, max_diff;
	R=dist.size();		C=dist[0].size();
	min_sum=R+C;		max_sum=-R-C;		min_diff=R+C;		max_diff=-R-C;
	for(i=0, flag=0; i<R; i++){
		for(j=0; j<C; j++){
			if(dist[i][j]>D){
				flag=1;
				min_sum=min(min_sum, i+j);
				max_sum=max(max_sum, i+j);
				min_diff=min(min_diff, i-j);
				max_diff=max(max_diff, i-j);
			}
		}
	}
	if(flag==0)
		return true;
	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			sum=i+j;
			diff=i-j;
			if(dist[i][j]>0 && max(abs(max_sum-sum), max(abs(sum-min_sum), max(abs(max_diff-diff), abs(diff-min_diff))))<=D)
				return true;
		}
	}
	return false;
}

int main(){
	int T, R, C, i, j, x, y, low, high, mid;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>R>>C;
		string grid[R];
		vector <vector<int>> dist;
		for(i=0; i<R; i++)
			cin>>grid[i];
		dist=bfs(grid, R, C);
		for(i=0, y=0; i<R; i++){
			for(j=0; j<C; j++)
				y=max(y, dist[i][j]);
		}
		low=0;		high=y;
		while(low<high){
			mid=low+(high-low)/2;
			if(binary_search(dist, mid))
				high=mid;
			else
				low=mid+1;
		}
		y=low;
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}