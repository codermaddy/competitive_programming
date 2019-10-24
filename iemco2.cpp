//ac

#include <bits/stdc++.h>
#define INF 1000
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N,M;
int dp[105][105];
int S[105],R[105];

int f(int idx,int sum){
  if(sum<0)
    return INF;
  if(idx>M-1)
    return INF;
  if(sum==0)
    return 0;
  if(dp[idx][sum]!=-1)
    return dp[idx][sum];
  else{
    dp[idx][sum]=min(f(idx,sum-R[idx])+1,min(f(idx+1,sum-R[idx])+1,f(idx+1,sum)));
    return dp[idx][sum];
  }
}

int main(){
  int T,i,count,ans,tmp;
  cin>>T;
  while(T--){
    memset(dp,-1,sizeof dp);
    count=ans=0;
    cin>>N>>M;
    for(i=0;i<N;i++){
      cin>>S[i];
    }
    for(i=0;i<M;i++){
      cin>>R[i];
    }
    for(i=0;i<N;i++){
      tmp=f(0,S[i]);
      if(tmp<INF){
        count++;
        ans+=tmp;
      }
    }
    cout<<count<<" "<<ans<<endl;
  }
  return 0;
}
