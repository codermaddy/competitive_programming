//ac

#include <bits/stdc++.h>

#define INF 999999999

using namespace std;

int N,x,y;
long long ans,dp[1005][1005][2],A[1005],C[1005];

long long f(int last,int i,int val){
	int l=i-last+1;
	//cout<<last<<" "<<i<<" "<<val<<" "<<l<<"\n";
	if(l-1<x && i>N)
		return INF;
	else if(l-1>y && i>N)
		return INF;
	else if(l-1>=x && l-1<=y && i>N)
		return 0;
	else if(dp[last][i][val]!=-1)
		return dp[last][i][val];
	else{
		if(l-1<x && A[i]!=val)
			dp[last][i][val]=C[i]+f(last,i+1,!A[i]);
		else if(l-1>=x && l-1<y && A[i]!=val)
			dp[last][i][val]=min(f(i,i+1,A[i]),C[i]+f(last,i+1,!A[i]));
		else if(l-1==y && A[i]!=val)
			dp[last][i][val]=f(i,i+1,A[i]);
		else if(l-1>y)
			return INF;
		else if(l-1<x && A[i]==val)
			dp[last][i][val]=f(last,i+1,A[i]);
		else if(l-1>=x && l-1<y && A[i]==val)
			dp[last][i][val]=min(f(last,i+1,A[i]),f(i,i+1,!A[i])+C[i]);
		else if(l-1==y && A[i]==val)
			dp[last][i][val]=f(i,i+1,!A[i])+C[i];
		return dp[last][i][val];
	}
}

int main(){

	freopen("grouping.in","r",stdin);
	freopen("grouping.out","w",stdout);

	int i,j,T;
	cin>>T;
	while(T--){
		cin>>N;
		cin>>x>>y;
		for(i=1;i<=N;i++){
			cin>>A[i];
		}
		for(i=1;i<=N;i++){
			cin>>C[i];
		}
		memset(dp,-1,sizeof dp);
		ans=f(1,2,A[1]);
		ans=min(ans,f(1,2,!A[1])+C[1]);
		if(ans>=INF)
			cout<<-1<<"\n";
		else
			cout<<ans<<"\n";
		/*for(i=0;i<=N;i++){
			for(j=1;j<=N;j++){
				cout<<dp[i][j][0]<<","<<dp[i][j][1]<<" ";
			}
			cout<<"\n";
		}*/
	}
	return 0;
}