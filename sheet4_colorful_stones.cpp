//ac

#include <bits/stdc++.h>

using namespace std;

int main(){
  string s,t;
  getline(cin,s);
  getline(cin,t);
  int pos=0;
  for(int i=0;i<t.size();i++){
    if(t[i]==s[pos])
      pos++;
  }
  cout<<pos+1<<"\n";
  return 0;
}