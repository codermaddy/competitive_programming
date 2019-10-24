//ac

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,h,tmp,ans=0;
  cin>>n>>h;
  for(int i=0;i<n;i++){
    cin>>tmp;
    ans++;
    if(tmp>h)
      ans++;
  }
  cout<<ans<<endl;
  return 0;
}
