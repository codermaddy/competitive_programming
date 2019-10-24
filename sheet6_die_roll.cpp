//ac

#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
  //cout<<a<<" "<<b<<"\n";
  if(b==0)
    return a;
  else
    return gcd(b,a%b);
}

int main(){
  int y,w,maxi,num;
  cin>>y>>w;
  maxi=max(y,w);
  num=6-maxi+1;
  //cout<<num<<"\n";
  cout<<num/gcd(6,num)<<"/"<<6/gcd(6,num)<<"\n";
  return 0;
}
