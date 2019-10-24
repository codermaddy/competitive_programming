#include <bits/stdc++.h>
#define INF 1000000001

using namespace std;

typedef long long ll;

int N;
int  S[3005];
int C[3005];
int dp[3005][3005][4];

int f(int last,int i,int more){
	//cout<<last<<" "<<i<<" "<<more<<"\n";
	if(i>N && more!=0)
		return INF;
	if(more==0)
		return 0;
	if(dp[last][i][more]!=-1)
		return dp[last][i][more];
	else{
		if(S[i]<=S[last])
			dp[last][i][more]=f(last,i+1,more);
		else
			dp[last][i][more]=min(f(last,i+1,more),f(i,i+1,more-1)+C[i]);
		return dp[last][i][more];
	}
}

int main(){

	//freopen("three_displays.in","r",stdin);
	//freopen("three_displays.out","w",stdout);

	int i,j,k;
	cin>>N;
	for(i=1;i<=N;i++){
		cin>>S[i];
	}
	for(i=1;i<=N;i++){
		cin>>C[i];
	}
	S[0]=-1*INF;
	C[0]=0;
	memset(dp,-1,sizeof dp);
	ll ans=f(0,1,3);
	if(ans>=INF)
		cout<<-1<<"\n";
	else
		cout<<ans<<"\n";
	/*for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			for(k=1;k<=3;k++){
				cout<<i<<" "<<j<<" "<<k<<" : "<<dp[i][j][k]<<"\n";
			}
		}
	}*/
	return 0;
}