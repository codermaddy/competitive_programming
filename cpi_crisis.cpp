#include <bits/stdc++.h>
#define NINF -999999999

using namespace std;

typedef long long ll;

int N,X;
int S[1005];
pair <ll,ll> dp[1005][1005];

int main(){
  int T,i,j;
  double opt1,opt2;
  cin>>T;
  while(T--){
    cin>>N>>X;
    for(i=1;i<=N;i++){
      cin>>S[i];
    }
    //initialize
    memset(dp,0,sizeof dp);
    for(i=1;i<=X;i++){
      dp[N+1][i].first=NINF;
      dp[N+1][i].second=1;
    }
    /*for(i=1;i<=N+1;i++){
      for(j=0;j<=X;j++){
        cout<<dp[i][j].first<<","<<dp[i][j].second<<"\t";
      }
      cout<<"\n";
    }*/
    //fill
    for(i=N;i>0;i--){
      for(j=X;j>0;j--){
        //cout<<i<<" "<<j<<endl;
        opt1 = (S[i]*i + dp[i+1][j-1].first)*1.0/(dp[i+1][j-1].second+i);
        opt2 = (dp[i+1][j].first)*1.0/dp[i+1][j].second;
        //cout<<i<<" "<<j<<" "<<opt1<<" "<<opt2<<endl;
        if(opt1>opt2){
          dp[i][j].first=S[i]*i+dp[i+1][j-1].first;
          dp[i][j].second=dp[i+1][j-1].second+i;
        }
        else{
          dp[i][j].first=dp[i+1][j].first;
          dp[i][j].second=dp[i+1][j].second;
        }
      }
    }
    /*for(i=1;i<=N+1;i++){
      for(j=0;j<=X;j++){
        cout<<dp[i][j].first<<","<<dp[i][j].second<<"\t";
      }
      cout<<"\n";
    }*/
    cout<<fixed<<setprecision(10)<<dp[1][X].first*1.0/dp[1][X].second<<endl;
  }
  return 0;
}
