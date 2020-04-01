#include <iostream>
#include <vector>
using namespace std;

long long int countLegalUpto(long long int N){
	long long int num, i, count;
	vector <int> digits;
	num=N-(N%10);
	while(num!=0){
		digits.push_back(num%10);
		num=num/10;
	}
	for(i=digits.size()-1, count=0; i>=0; i--)
		count=count*9+digits[i];
	for(i=N-(N%10), count=8*count/9; i<=N; i++){
		if(i%9!=0)
			count++;
	}
	return count;
}

int main(){
	long long int T, F, L, x, y;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>F>>L;
		y=countLegalUpto(L)-countLegalUpto(F)+1;
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}