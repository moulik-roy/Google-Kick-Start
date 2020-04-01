#include <iostream>
#include <vector>
using namespace std;

int main(){
	int T, L, x, y, i, j, k, length, flag;
	string A, B;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>L;
		cin>>A>>B;
		vector <vector<int>> dp_A(L+1, vector<int>(26, 0)), dp_B(L+1, vector<int>(26, 0));
		for(i=0; i<L; i++){
			for(j=0; j<26; j++){
				dp_A[i+1][j]=dp_A[i][j];
				dp_B[i+1][j]=dp_B[i][j];
			}
			dp_A[i+1][A[i]-'A']++;
			dp_B[i+1][B[i]-'A']++;
		}
		for(length=0, y=0; length<L; length++){
			for(i=0; i<L-length; i++){
				for(j=0, flag=0; j<L-length && flag==0; j++){
					for(k=0; k<26; k++){
						if(dp_A[i+length+1][k]-dp_A[i][k]!=dp_B[j+length+1][k]-dp_B[j][k])
							break;
					}
					if(k==26)
						flag=1;
				}
				if(flag==1)
					y++;
			}
		}
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}