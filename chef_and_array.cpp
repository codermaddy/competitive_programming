#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
  int N,M,i,j;
  srand(time(0));
  ll K;
  ull prod=1;
  cin>>N>>M>>K;
  int A[10005],P[10005],D[10005];
  for(i=0;i<N;i++){
    cin>>A[i];
  }
  for(j=0;j<M;j++){
    cin>>P[i];
  }
  for(i=0;i<N;i++){
    D[i]=(rand())%(K+1);
  }
  for(i=0;i<N;i++){
    A[i]+=D[i];
  }
  for(i=0;i<N;i++){
    cout<<A[i]<<" ";
  }
  cout<<"\n";
  return 0;
}
