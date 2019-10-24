//ac

#include <bits/stdc++.h>
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
  int tmp,N,i,sum1=0,sum2=0;
  vector <int> p;
  cin>>N;
  for(i=1;i<=N/2;i++){
    cin>>tmp;
    p.pb(tmp);
  }
  sort(p.begin(),p.end());
  //white
  for(i=1;i<=N/2;i++){
    sum1+=abs(p[i-1]-2*i);
  }
  //black
  for(i=1;i<=N/2;i++){
    sum2+=abs(p[i-1]-(2*i-1));
  }
  //cout<<sum1<<" "<<sum2<<"\n";
  cout<<min(sum1,sum2)<<"\n";
  return 0;
}
