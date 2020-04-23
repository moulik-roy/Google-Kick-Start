#include <iostream>
#include <stack>
#include <utility>
#define MOD 1000000000
using namespace std;

int main(){
	long int T, i, x, w, h, rem;
	string S;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>S;
		stack <long int> count;
		stack <pair<long int, long int>> st;
		for(i=0, w=0, h=0; i<S.length(); i++){
			if(S[i]>='0' && S[i]<='9'){
				rem=0;
				while(i<S.length() && S[i]>='0' && S[i]<='9'){
					rem=(rem*10+(S[i]-'0'))%MOD;
					i++;
				}
				count.push(rem);
				i--;
			}
			else if(S[i]=='('){
				st.push(make_pair(w, h));
				w=0;
				h=0;
			}
			else if(S[i]==')'){
				w*=count.top();
				h*=count.top();
				count.pop();
				w+=st.top().first;
				h+=st.top().second;
				st.pop();
				if(w<0)
					w=MOD-((-w)%MOD);
				else
					w%=MOD;
				if(h<0)
					h=MOD-((-h)%MOD);
				else
					h%=MOD;
			}
			else{
				if(S[i]=='E')
					w++;
				else if(S[i]=='W')
					w--;
				else if(S[i]=='S')
					h++;
				else if(S[i]=='N')
					h--;
			}
		}
		if(w<0)
			w=MOD-((-w)%MOD);
		else
			w%=MOD;
		if(h<0)
			h=MOD-((-h)%MOD);
		else
			h%=MOD;
		w++;
		h++;
		cout<<"Case #"<<x<<": "<<w<<" "<<h<<"\n";
	}
	return 0;
}