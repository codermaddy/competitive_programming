//may long '18
//ac(iterartion with fast I/O rocks)

#include <bits/stdc++.h>
#define INF 10000000000

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll A[100005];
char ans[100005][2];
ll dp[100005][2];
pair <int,bool> store[100005][2];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N,T,i,tmp,i_s;
  cin>>T;
  while(T--){
    cin>>N;
    A[0]=INF;
    for(i=1;i<=N;i++){
      cin>>A[i];
    }
    A[N+1]=INF;
    if(A[N-1]>A[N]){
      dp[N][0]=-1*A[N];
      ans[N][0]='-';
      store[N][0].first=N+1;
      store[N][0].second=0;
    }
    else{
      dp[N][0]=1*A[N];
      ans[N][0]='+';
      store[N][0].first=N+1;
      store[N][0].second=0;
    }
    if(A[N-1]-A[N-2]-A[N]>0){
      dp[N][1]=-1*A[N];
      ans[N][1]='-';
      store[N][1].first=N+1;
      store[N][1].second=0;
    }
    else{
      dp[N][1]=1*A[N];
      ans[N][1]='+';
      store[N][1].first=N+1;
      store[N][1].second=0;
    }
    dp[N+1][0]=0;
    dp[N+1][1]=0;
    for(i=N-1;i>=1;i--){
      if(A[i]>=A[i+1] || A[i]>=A[i-1]){
        dp[i][0]=dp[i][1]=dp[i+1][0]+A[i];
        ans[i][0]=ans[i][1]='+';
        store[i][0].first=store[i][1].first=i+1;
        store[i][0].second=store[i][1].second=0;
      }
      else{
        ll ch1=dp[i+2][1]-A[i]+A[i+1];
        ll ch2=dp[i+2][0]+A[i]+A[i+1];
        if(ch1<ch2){
          dp[i][0]=ch1;
          ans[i][0]='-';
          store[i][0].first=i+2;
          store[i][0].second=1;
          if(i>=2 && A[i-1]-A[i-2]-A[i]>0){
            dp[i][1]=ch1;
            ans[i][1]='-';
            store[i][1].first=i+2;
            store[i][1].second=1;
          }
          else if(i>=2 && A[i-1]-A[i-2]-A[i]<=0){
            dp[i][1]=dp[i+1][0]+A[i];
            ans[i][1]='+';
            store[i][1].first=i+2;
            store[i][1].second=0;
          }
        }
        else{
          dp[i][0]=ch2;
          ans[i][0]='+';
          store[i][0].first=i+2;
          store[i][0].second=0;
          if(i>=2 && A[i-1]-A[i-2]-A[i]>0){
            dp[i][1]=ch2;
            ans[i][1]='+';
            store[i][1].first=i+2;
            store[i][1].second=0;
          }
          else if(i>=2 && A[i-1]-A[i-2]-A[i]<=0){
            dp[i][1]=dp[i+1][0]+A[i];
            ans[i][1]='+';
            store[i][1].first=i+2;
            store[i][1].second=0;
          }
        }
      }
    }
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
