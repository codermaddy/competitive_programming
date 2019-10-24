//may long'18
//ac

#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
  int T,N,M,i;
  ll fib[1000005],tmp;
  ull sum1,sum2;
  cin>>T;
  while(T--){
    cin>>M>>N;
    sum1=sum2=0;
    for(i=0;i<M;i++){
      cin>>tmp;
      sum1+=tmp;
    }
    for(i=0;i<M;i++){
      cin>>tmp;
      sum2+=tmp;
    }
    fib[1]=(M*sum1)%MOD;
    fib[2]=(M*sum2)%MOD;

    for(i=3;i<=N;i++){
      fib[i]=(fib[i-1]+fib[i-2])%MOD;
    }
    cout<<fib[N]<<"\n";
  }
  return 0;
}
