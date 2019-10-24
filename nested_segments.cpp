//ac

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
  vector <tuple <ll,ll,int> > t;
  int i,N;
  bool flag=0;
  ll a,b;
  cin>>N;
  for(i=0;i<N;i++){
    cin>>a>>b;
    t.push_back(make_tuple(a,b,i+1));
  }
  sort(t.begin(),t.end());
  /*for(i=0;i<N;i++){
    cout<<get<0>(t[i])<<" "<<get<1>(t[i])<<" "<<get<2>(t[i])<<"\n";
  }*/
  for(i=0;i<N-1;i++){
    if(get<1>(t[i]) >= get<1>(t[i+1])) {
      cout<<get<2>(t[i+1])<<" "<<get<2>(t[i])<<"\n";
      flag=1;
      break;
    }
    else if(get<0>(t[i])==get<0>(t[i+1]) && get<1>(t[i])<get<1>(t[i+1])){
      cout<<get<2>(t[i])<<" "<<get<2>(t[i+1])<<"\n";
      flag=1;
      break;
    }
  }
  if(!flag)
    cout<<-1<<" "<<-1<<"\n";
  return 0;
}
