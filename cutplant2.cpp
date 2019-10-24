//partial
//april long'18

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll A[100005],B[100005];

ll calc(int u,int v,ll limit){
  int i;
  bool abc=0;
  ll ans=0;
  //all are equal?
  for(i=u;i<=v;i++){
    if(A[i]!=B[i]){
      abc=1;
      break;
    }
  }
  if(abc==0)
    return 0;
  else{
    for(i=u;i<=v;i++){
      ans+=limit-B[i];
    }
    return ans+1;
  }
}

int main(){
  int T,N,i,start,end;
  ll low,high,high_tmp,sum;
  bool flag;
  cin>>T;
  while(T--){
    //entry
    cin>>N;
    for(i=0;i<N;i++){
      cin>>A[i];
    }
    for(i=0;i<N;i++){
      cin>>B[i];
    }
    //checking for -1
    flag=0;
    for(i=0;i<N;i++){
      if(A[i]<B[i])
        flag=1;
    }
    if(flag==1)
      cout<<-1<<"\n";
    else{
      i=0;
      sum=0;
      while(i<N){
        start=i;
        low=A[i];
        high=B[i];
        high_tmp=B[i];
        while(i<N){
          if(A[i]<high){
              end=--i;
              break;
          }
          if(high<B[i])
            high_tmp=B[i];
          if(low>A[i])
            low=A[i];
          if(high_tmp>low){
            end=--i;
            break;
          }
          high=high_tmp;
          i++;
        }
        if(i==N)
          sum+=calc(start,N-1,high);
        else
          sum+=calc(start,end,high);
        i++;
      }
      cout<<sum<<"\n";
    }
  }
  return 0;
}
