//ac

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,anton=0,danik=0;
  char won;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>won;
    if(won=='A')
      anton++;
    else
      danik++;
  }
  if(anton>danik)
    cout<<"Anton\n";
  else if(danik>anton)
    cout<<"Danik\n";
  else
    cout<<"Friendship\n";
  return 0;
}
