#include <iostream>
#include <string>
using namespace std;

int main(){
	int T, x, y, i, count;
	string S;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>S;
		for(i=0, count=0, y=0; i+4<S.length(); i++){
			if(S[i]=='K' && S.substr(i, 4).compare("KICK")==0)
				count++;
			else if(S[i]=='S' && S.substr(i, 5).compare("START")==0)
				y+=count;
		}
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}