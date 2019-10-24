//ac

#include <bits/stdc++.h>

using namespace std;

vector <long long> A;
long long H;
int N;

long long P(long long K){
  long long sum=0;
  int i;
  for(i=0;i<N;i++){
    if(A[i]%K==0)
      sum+=A[i]/K;
    else
      sum+=A[i]/K + 1;
  }
  //cout<<K<<" "<<sum<<endl;
  return sum;
}

long long K(long long lo,long long hi){
  long long mid;
  while(lo<hi){
    mid=lo+(hi-lo)/2;
    if(P(mid)<=H)
      hi=mid;
    else
      lo=mid+1;
  }
  return lo;
}

int main(){
  int i,T,j;
  long long tmp;
  cin>>T;
  while(T--){
    cin>>N>>H;
    for(i=0;i<N;i++){
      cin>>tmp;
      A.push_back(tmp);
    }
    cout<<K(1,1000000000)<<endl;
    A.clear();
  }
  return 0;
}
