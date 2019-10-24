//ac

#include <bits/stdc++.h>
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
  //cout<<"ok";
  int i,j,n,m;
  int A[2005][2005];
  bool flag;
  int sizex[2005];
  string s[2005];
  memset(sizex,0,sizeof sizex);
  cin>>n>>m;
  for(i=1;i<=n;i++){
    cin>>s[i];
  }
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      A[i][j]=s[i][j-1]-'0';
      if(A[i][j])
        sizex[j]++;
    }
  }
  /*for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      cout<<A[i][j]<<" ";
    }
    cout<<"\n";
  }*/
  for(i=1;i<=n;i++){
    flag=1;
    for(j=1;j<=m;j++){
      if(A[i][j] && sizex[j]<=1){
        flag=0;
        break;
      }
    }
    //cout<<flag<<" ";
    if(flag==1)
      break;
  }
  if(flag)
    cout<<"YES\n";
  else
    cout<<"NO\n";
  return 0;
}
