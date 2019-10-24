//ac
//inoi

#include <bits/stdc++.h>
#define INF 999999999
using namespace std;

int C,F;
int dp[235][235];
int adj[235][235];

void floyd_warshall(){
	int i,j,k;
	for(i=1;i<=C;i++){
		for(j=1;j<=C;j++){
			for(k=1;k<=C;k++){
				dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
			}
		}
	}
}

int main(){
	int i,j,maxi,a,b,p;
	memset(adj,-1,sizeof adj);
	cin>>C>>F;
	for(i=0;i<F;i++){
		cin>>a>>b>>p;
		adj[a][b]=p;
		adj[b][a]=p;
	}
	for(i=1;i<=C;i++){
		for(j=1;j<=C;j++){
			if(i==j)
				dp[i][j]=0;
			else if(adj[i][j]<0)
				dp[i][j]=INF;
			else
				dp[i][j]=adj[i][j];
		}
	}
	floyd_warshall();
	maxi=-1;
	for(i=1;i<=C;i++){
		for(j=1;j<=C;j++){
			maxi=max(maxi,dp[i][j]);
		}
	}
	cout<<maxi<<endl;
	return 0;
}
