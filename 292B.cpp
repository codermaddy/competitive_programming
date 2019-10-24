//ac

#include <bits/stdc++.h>

using namespace std;

int main(){

	//freopen("292B.in","r",stdin);
	//freopen("292B.out","w",stdout);

	int i,N,M,x,y,degree[4];
	bool flag=0;
	vector <int> adj[100005];
	cin>>N>>M;
	for(i=0;i<M;i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(i=1;i<=N;i++){
		if(adj[i].size()==1)
			degree[1]++;
		else if(adj[i].size()==2)
			degree[2]++;
		else if(adj[i].size()==N-1)
			degree[3]++;
	}
	if(degree[1]==2 && degree[2]==N-2)
		cout<<"bus topology\n";
	else if(degree[1]==N-1 && degree[3]==1)
		cout<<"star topology\n";
	else if(degree[2]==N)
		cout<<"ring topology\n";
	else
		cout<<"unknown topology\n";
	return 0;
}