//ac

#include <bits/stdc++.h>
#define pb push_back

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
  int T;
  vector<ull> sumdp;
  ull sum=1,X;
  int i=1;
  sumdp.pb(0);
  while(i<=100000){
    sumdp.pb(sum);
    i++;
    sum+=i;
  }
  /*for(i=0;i<50;i++){
    cout<<sumdp[i]<<" ";
  }*/
  cin>>T;
  while(T--){
    cin>>X;
    int ans1=lower_bound(sumdp.begin(),sumdp.end(),X)-sumdp.begin();
    //cout<<ans1<<" ";
    if(sumdp[ans1]==X)
      cout<<ans1<<endl;
    else
      cout<<min(ans1+X-sumdp[ans1-1]-1,ans1+sumdp[ans1]-X)<<endl;
  }
}
