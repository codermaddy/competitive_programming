#include <bits/stdc++.h>

using namespace std;

vector <int> adj[105];
int W[105],P[105];

int main(){
	int i,T;
	cin>>T;
	while(T--){
		cin>>N;
		for(i=1;i<=N;i++){
			cin>>W[i];
		}
		for(i=2;i<=N;i++){
			cin>>P[i];
			adj[P[i]].push_back(i);
		}
	}
	return 0;
}