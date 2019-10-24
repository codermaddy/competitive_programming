//ac

#include <bits/stdc++.h>

using namespace std;

int main(){
  unsigned long long n,m,k;
  cin>>n>>m>>k;
  if(k<n)
    cout<<k+1<<" "<<1;
  else if(k==n)
    cout<<n<<" "<<2;
  else{
    unsigned long long i= (k-n)/(m-1);
    cout<<n-i<<" ";
    if(i%2)
      cout<<m-(k-n)%(m-1);
    else
      cout<<2+(k-n)%(m-1);
  }
  cout<<"\n";
  return 0;
}
