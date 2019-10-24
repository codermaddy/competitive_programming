//ac

#include <bits/stdc++.h>

using namespace std;

int main(){
  int i,N,T,p,q,d;
  double sum;
  double tmp1,tmp2;
  vector<int> P;
  vector<int> Q;
  vector<int> D;
  cin>>T;
  while(T--){
    cin>>N;
    for(i=0;i<N;i++){
      cin>>p>>q>>d;
      P.push_back(p);
      Q.push_back(q);
      D.push_back(d);
    }
    sum=0;
    for(i=0;i<N;i++){
      tmp1=P[i]+D[i]*P[i]/100.000000;
      tmp2=P[i]-(tmp1-D[i]*tmp1/100.000000);
      sum+=tmp2*Q[i];
      //cout<<P[i]<<" "<<D[i]<<" "<<Q[i]<<" "<<tmp1<<" "<<tmp2<<"\n";
    }
    cout<<fixed<<setprecision(7)<<sum<<"\n";
    P.clear();
    Q.clear();
    D.clear();
  }
  return 0;
}
