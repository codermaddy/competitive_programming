//ac

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,k;
  string ans;
  cin>>n>>k;
  char start='a';
  for(int i=1;i<=k;i++){
    ans.push_back(start);
    cout<<start;
    start++;
  }
  //cout<<ans<<endl;
  int i=k+1;
  int j=0;
  while(i<=n){
    if(j==ans.size())
      j=0;
    cout<<ans[j];
    i++;
    j++;
  }
  cout<<"\n";
  return 0;
}
