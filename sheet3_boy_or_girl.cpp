//ac

#include <bits/stdc++.h>

using namespace std;

int main(){
  string name;
  char x;
  bool freq[28];
  int cnt=0;
  memset(freq,0,sizeof freq);
  getline(cin,name);
  for(int i=0;i<name.size();i++){
    x=name[i];
    if(!freq[x-'a'])
      cnt++;
    freq[x-'a']=1;
  }
  if(cnt%2==1)
    cout<<"IGNORE HIM!\n";
  else
    cout<<"CHAT WITH HER!\n";
  return 0;
}
