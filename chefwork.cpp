//ac
//april long'18
#include <iostream>

using namespace std;

int main(){
  int N,i,t,min_a,min_tr,min_at;
  min_a=min_tr=min_at=999999;
  int C[1005];
  cin>>N;
  for(i=0;i<N;i++){
    cin>>C[i];
  }
  for(i=0;i<N;i++){
    cin>>t;
    if(t==1){
      if(C[i]<min_tr)
        min_tr=C[i];
    }
    else if(t==2){
      if(C[i]<min_a)
        min_a=C[i];
    }
    else{
      if(C[i]<min_at)
        min_at=C[i];
    }
  }
  (min_a+min_tr>min_at)?cout<<min_at:cout<<min_a+min_tr;
  cout<<"\n";
  return 0;
}
