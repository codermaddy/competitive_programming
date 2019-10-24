#include <bits/stdc++.h>

using namespace std;

int main(){
  int T=1;
  cout<<T<<endl;
  while(T--){
    cout<<100000<<endl;
    for(int i=-1000;i<=1000;i++){
      if(i!=0){
        for(int j=1;j<=50;j++){
          cout<<i<<" ";
        }
      }
    }
  }
    return 0;
}
