//ac

#include <bits/stdc++.h>

using namespace std;

vector <int> A;
int N;
long long dp[1005];

long long f(int i){
  if(i>N)
    return 0;
  if(dp[i]!=-1)
    return dp[i];
  else{
    long long maxi=0;
    for(int j=i+1;j<=N;j++){
      if(A[j]>A[i])
        maxi=max(maxi,f(j));
    }
    dp[i]=maxi+A[i];
    return dp[i];
  }
}

int main(){
  int T,i,tmp;
  cin>>T;
  while(T--){
    memset(dp,-1,sizeof dp);
    cin>>N;
    A.push_back(0);
    for(i=0;i<N;i++){
      cin>>tmp;
      A.push_back(tmp);
    }
    cout<<f(0)<<"\n";
    A.clear();
  }
  return 0;
}
