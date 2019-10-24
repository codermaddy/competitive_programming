//ac

#include <bits/stdc++.h>
#define pb push_back

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
  int T,N,i;
  int tmp,maxa,maxb;
  ll sum1,sum2;
  cin>>T;
  while(T--){
    sum1=sum2=maxa=maxb=0;
    cin>>N;
    for(i=0;i<N;i++){
      cin>>tmp;
      sum1+=tmp;
      if(tmp>maxa)
        maxa=tmp;
    }
    for(i=0;i<N;i++){
      cin>>tmp;
      sum2+=tmp;
      if(tmp>maxb)
        maxb=tmp;
    }
    if(sum1-maxa>sum2-maxb)
      cout<<"Bob";
    else if(sum1-maxa<sum2-maxb)
      cout<<"Alice";
    else
      cout<<"Draw";
    cout<<endl;
  }
  return 0;
}
