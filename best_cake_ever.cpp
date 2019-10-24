//ac

#include <bits/stdc++.h>

using namespace std;

int main(){
  int T,N,numbit;
  long long K,grtnum,xorval;
  cin>>T;
  while(T--){
    xorval=0;
    cin>>N>>K;
    numbit=log2(K);
    grtnum=pow(2,numbit);
    if(N==1){
      xorval=K;
      cout<<K;
    }
    else if(K==1){
      for(int i=1;i<=N;i++){
        cout<<1<<" ";
        xorval ^= 1;
      }
    }
    else if(N%2==0){
      for(int i=2;i<=N;i++){
        cout<<grtnum-1<<" ";
        xorval ^= grtnum-1;
      }
      cout<<grtnum;
      xorval ^= grtnum;
    }
    else {
      if(numbit==1){
        for(int i=1;i<=N;i++){
          cout<<K<<" ";
          xorval ^= K;
        }
      }
      else{
        cout<<1<<" ";
        xorval ^= 1;
        for(int i=2;i<N;i++){
          cout<<grtnum-2<<" ";
          xorval ^= grtnum-2;
        }
        cout<<grtnum;
        xorval ^= grtnum;
      }
    }
    //cout<<"\n"<<xorval;
    cout<<"\n";
  }
  return 0;
}
