//ac

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,i,cnt=0;
  string s;
  cin>>n;
  cin>>s;
  if(s=="0")
    cout<<0<<endl;
  else{
    for(i=0;i<s.length();i++){
      if(s[i]=='0')
        cnt++;
    }
    cout<<1;
    for(i=0;i<cnt;i++)
      cout<<0;
    cout<<"\n";
  }
  return 0;
}
