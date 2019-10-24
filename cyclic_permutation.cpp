#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i,n,j,x,count=0;
	bool vis[10001];
	vector<int> A;
	vector<int> X[1000];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x;
		A.push_back(x);
	}
	memset(vis,0,sizeof vis);
	for(i=0;i<n;i++){
		if(vis[i])
			continue;
		count++;
		vis[i]=1;
		x=A[i]-1;
		vis[x]=1;
		X[i].push_back(i+1);
		while(x!=i){
			X[i].push_back(x+1);
			vis[x]=1;
			x=A[x]-1;
		}
		X[i].push_back(i+1);
	}
	cout<<count<<endl;
	for(i=0;i<n;i++){
		for(j=0;j<X[i].size();j++){
			cout<<X[i][j]<<" ";
			if(j==X[i].size()-1)
				cout<<"\n";
		}
	}
	return 0;
}			
