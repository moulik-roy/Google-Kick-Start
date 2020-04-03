#include <iostream>
using namespace std;

struct TrieNode{
	TrieNode *children[26];
	int prefix_count, word_count;

	TrieNode(){
		for(int i=0; i<26; i++)
			children[i]=NULL;
		prefix_count=0;
		word_count=0;
	}
};

void insert(TrieNode *root, string S){
	for(int i=0; i<S.length(); i++){
		root->prefix_count++;
		if(root->children[S[i]-'A']==NULL)
			root->children[S[i]-'A']=new TrieNode();
		root=root->children[S[i]-'A'];
	}
	root->prefix_count++;
	root->word_count++;
}

int dfs(TrieNode *root, int K, int depth){
	if(root->prefix_count<K)
		return 0;
	int i, rem, max_score;
	for(i=0, rem=root->word_count, max_score=0; i<26; i++){
		if(root->children[i]!=NULL){
			max_score=max_score+dfs(root->children[i], K, depth+1);
			rem=rem+(root->children[i]->prefix_count%K);
		}
	}
	max_score=max_score+(depth*(rem/K));
	return max_score;
}

int main(){
	int T, N, K, i, x, y;
	string S;
	cin>>T;
	for(x=1; x<=T; x++){
		cin>>N>>K;
		TrieNode *root=new TrieNode();
		for(i=0; i<N; i++){
			cin>>S;
			insert(root, S);
		}
		y=dfs(root, K, 0);
		cout<<"Case #"<<x<<": "<<y<<"\n";
	}
	return 0;
}