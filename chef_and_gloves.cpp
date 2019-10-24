//ac

#include <bits/stdc++.h>

using namespace std;

int main(){
  int i,T,N;
  bool front,back;
  vector <long long> L;
  vector <long long> B;
  long long tmp;
  cin>>T;
  while(T--){
    cin>>N;
    for(i=0;i<N;i++){
      cin>>tmp;
      L.push_back(tmp);
    }
    for(i=0;i<N;i++){
      cin>>tmp;
      B.push_back(tmp);
    }
    //checking for front
    front=1;
    for(i=0;i<N;i++){
      if(B[i]<L[i]){
        front=0;
        break;
      }
    }
    //checking for back
    back=1;
    for(i=0;i<N;i++){
      if(B[i]<L[N-i-1]){
        back=0;
        break;
      }
    }
    if(!front && !back)
      cout<<"none\n";
    else if(front && back)
      cout<<"both\n";
    else if(!front && back)
      cout<<"back\n";
    else
      cout<<"front\n";
    L.clear();
    B.clear();
  }
  return 0;
}
