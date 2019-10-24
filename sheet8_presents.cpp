#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,tmp;
  int giver[105];
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>tmp;
    giver[tmp]=i;
  }
  for(int i=1;i<=n;i++){
    cout<<giver[i]<<" ";
  }
  cout<<"\n";
  return 0;
}
