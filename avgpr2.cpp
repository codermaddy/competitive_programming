//ac
//april long'18
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  int T,i,N,j,avg;
  cin>>T;
  while(T--){
    ll tmp,freq[2001],ans=0;
    for(i=0;i<2001;i++){
      freq[i]=0;
    }
    cin>>N;
    for(i=0;i<N;i++){
      cin>>tmp;
      freq[tmp]++;
    }
    for(i=-1000;i<=1000;i++){
      for(j=-1000;j<=1000;j++){
        if(freq[i+1000]>0 && freq[j+1000]>0){
          avg=i+j+2000;
          if(avg%2==0 && freq[avg/2]>0 && i!=j)
            ans+=freq[i+1000]*freq[j+1000];
          if(i==j && freq[i+1000]>=2)
            ans+=freq[i+1000]*(freq[i+1000]-1);
        }
      }
    }
    cout<<ans/2<<"\n";
  }
  return 0;
}
