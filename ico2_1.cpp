#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define INF 999999999
#define MOD 1000000009

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int K,N,B[105];
ll dp[105][105];

int main(){

	freopen("ico2_1.in","r",stdin);
	freopen("ico2_1.out","w",stdout);

	int i,n,x,T;
	cin>>T;
	while(T--){
		cin>>N>>K;
		for(i=1;i<=K;i++){
			cin>>B[i];
		}
		/*for(i=1;i<=K;i++){
			cout<<B[i]<<"\n";
		}*/
		for(i=1;i<=N;i++){
			dp[K+1][i]=0;
		}
		dp[K+1][0]=1;
		for(i=K;i>=1;i--){
			for(n=0;n<=N;n++){
				ll sum=0;
				for(x=0;x<=min(B[i],n);x++){
					sum = (sum+dp[i+1][n-x])%MOD;
				}
				dp[i][n]=sum%MOD;
				//cout<<sum<<"\n";
			}
		}
		cout<<dp[1][N]<<"\n";
	}
	return 0;
}