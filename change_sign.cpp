//may long '18
//partial(tle--50/100)

#include <bits/stdc++.h>
#define INF 10000000000

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll A[100005];
char ans[100005][2];
ll dp[100005][2];
pair <int,bool> store[100005][2];
int N;

ll f(int i,bool state){
  //cout<<i<<" "<<state<<"\n";
  if(i>N)
    return 0;
  if(dp[i][state]!=-1)
    return dp[i][state];
  else{
    if(A[i]>=A[i+1] || A[i]>=A[i-1]){
      dp[i][state]=f(i+1,0)+A[i];
      ans[i][state]='+';
      store[i][state].first=i+1;
      store[i][state].second=0;
    }
    else{
      if(i==N && state==0){
        dp[i][state]=-1*A[i];
        ans[i][state]='-';
        store[i][state].first=i+1;
        store[i][state].second=0;
      }
      else if(i==N && state==1 && A[i-1]-A[i-2]-A[i]>0){
        dp[i][state]=-1*A[i];
        ans[i][state]='-';
        store[i][state].first=i+1;
        store[i][state].second=0;
      }
      else if(i==N && state==1 && A[i-1]-A[i-2]-A[i]<=0){
        dp[i][state]=A[i];
        ans[i][state]='+';
        store[i][state].first=i+1;
        store[i][state].second=0;
      }
      else if(state==1 && A[i-1]-A[i-2]-A[i]<=0){
        dp[i][state]=f(i+1,0)+A[i];
        ans[i][state]='+';
        store[i][state].first=i+1;
        store[i][state].second=0;
      }
      else if(state==0){
        ll ch1=f(i+2,1)-A[i]+A[i+1];
        ll ch2=f(i+2,0)+A[i]+A[i+1];
        ans[i+1][0]='+';
        if(ch1>ch2){
          dp[i][state]=ch2;
          ans[i][state]='+';
          store[i][state].first=i+2;
          store[i][state].second=0;
        }
        else{
          dp[i][state]=ch1;
          ans[i][state]='-';
          store[i][state].first=i+2;
          store[i][state].second=1;
        }
      }
      else if(state==1 && A[i-1]-A[i-2]-A[i]>0){
        ll ch1=f(i+2,1)-A[i]+A[i+1];
        ll ch2=f(i+2,0)+A[i]+A[i+1];
        ans[i+1][0]='+';
        if(ch1>ch2){
          dp[i][state]=ch2;
          ans[i][state]='+';
          store[i][state].first=i+2;
          store[i][state].second=0;
        }
        else{
          dp[i][state]=ch1;
          ans[i][state]='-';
          store[i][state].first=i+2;
          store[i][state].second=1;
        }
      }
    }
    //cout<<i<<" "<<state<<" "<<dp[i][state]<<"\n";
    return dp[i][state];
  }
}

int main(){
  int T,i,tmp,i_s;
  //ll ans;
  cin>>T;
  while(T--){
    cin>>N;
    A[0]=INF;
    for(i=1;i<=N;i++){
      cin>>A[i];
    }
    A[N+1]=INF;
    memset(dp,-1,sizeof dp);
    ull res=f(1,0);
    //cout<<res<<"\n";
    i=1;
    i_s=0;
    while(i<=N){
      //cout<<i<<" "<<i_s<<"-->";
      if(ans[i][i_s]=='+')
        cout<<A[i]<<" ";
      else
        cout<<ans[i][i_s]<<A[i]<<" ";
      tmp=store[i][i_s].first;
      if(tmp-i==2 && i+1<=N)
        cout<<A[i+1]<<" ";
      i_s=store[i][i_s].second;
      i=tmp;
    }
    cout<<"\n";
  }
  return 0;
}
