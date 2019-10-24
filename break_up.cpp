//wa

int N;
#include <bits/stdc++.h>

using namespace std;

vector<long long> A;
bool ispalin[305][305];
bool vis[305][305];
int dp[305];

bool palin(int i,int j){
  //cout<<i<<" "<<j<<endl;
  if(vis[i][j])
    return ispalin[i][j];
  else{
    vis[i][j]=1;
    if(i==j)
      ispalin[i][j]=1;
    else if(i>j)
      ispalin[i][j]=0;
    else if(A[i]!=A[j])
      ispalin[i][j]=0;
    else if(A[i]==A[j] && i+1!=j)
      ispalin[i][j]=palin(i+1,j-1);
    else if(A[i]==A[j] && i+1==j)
      ispalin[i][j]=1;
    return ispalin[i][j];
  }
}

int main(){
  int i,j;
  long long tmp;
  bool x;
  memset(vis,0,sizeof vis);
  memset(dp,-1,sizeof dp);
  cin>>N;
  for(i=0;i<N;i++){
    cin>>tmp;
    A.push_back(tmp);
  }
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      x=palin(i,j);
      //cout<<i<<" "<<j<<" "<<x<<endl;
    }
  }
  /*cout<<breakup(0)<<endl;
  for(i=0;i<N;i++){
    cout<<dp[i]<<endl;
  }*/
  for(i=N;i>=0;i--){
    dp[i]=N+1;
    for(j=i;j<N;j++){
      if(ispalin[i][j])
        dp[i]=min(dp[i],dp[j+1]+1);
    }
    cout<<dp[i]<<endl;
  }
  cout<<dp[0]<<endl;
  return 0;
}
