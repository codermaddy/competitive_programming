//ac

#include <bits/stdc++.h>

using namespace std;

int main(){
  int T,R,B,N;
  char ch;
  cin>>T;
  while(T--){
    cin>>R>>B;
    cin>>ch>>N;
    if(ch=='R')
      R-=N;
    else
      B-=N;
    //cout<<R<<" "<<B<<endl;
    if(R==B)
      cout<<"Oj\n";
    else
      cout<<"Bhrigudov\n";
  }
  return 0;
}
