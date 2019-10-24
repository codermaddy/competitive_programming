//ac

#include <bits/stdc++.h>

using namespace std;

int main(){
  int count[4]={0,0,0,0};
  string S;
  getline(cin,S);
  for(int i=0;i<S.size();i++){
    if(S[i]=='1')
      count[1]++;
    else if(S[i]=='2')
      count[2]++;
    else if(S[i]=='3')
      count[3]++;
  }
  S.clear();
  for(int i=0;i<count[1];i++){
    S.push_back('1');
    S.push_back('+');
  }
  for(int i=0;i<count[2];i++){
    S.push_back('2');
    S.push_back('+');
  }
  for(int i=0;i<count[3];i++){
    S.push_back('3');
    S.push_back('+');
  }
  for(int i=0;i<S.size()-1;i++){
    cout<<S[i];
  }
  cout<<"\n";
  return 0;
}
