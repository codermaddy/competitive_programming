//ac

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll A[105][105],last;
  int T,N,M,i,j;
  bool flag;
  cin>>T;
  while(T--){
    flag=0;
    cin>>N>>M;
    for(i=0;i<N;i++){
      for(j=0;j<M;j++){
        cin>>A[i][j];
      }
    }
    for(i=0;i<N;i++){
      if(A[i][0]==-1 && i!=0){
          A[i][0]=A[i-1][0];
          //cout<<i<<" "<<0<<endl;
      }
      if(A[i][0]==-1 && i==0){
        A[i][0]=1;
      }
    }
    //check 1
    for(i=0;i<N && flag!=1;i++){
      last=0;
      for(j=0;j<M;j++){
        if(A[i][j]<last && A[i][j]!=-1){
          flag=1;
          //cout<<i<<" "<<j<<"1";
          break;
        }
        if(A[i][j]!=-1)
          last=A[i][j];
      }
    }
    //check 2
    for(j=0;j<M && flag!=1;j++){
      last=0;
      for(i=0;i<N;i++){
        if(A[i][j]<last && A[i][j]!=-1){
          flag=1;
          //cout<<i<<" "<<j<<"2";
          break;
        }
        if(A[i][j]!=-1)
          last=A[i][j];
      }
    }
    //check 3
    for(i=0;i<N && flag!=1;i++){
      for(j=0;j<M && flag!=1;j++){
        if(A[i][j]==-1){
          //cout<<i<<" "<<j<<" "<<A[i-1][j]<<" "<<A[i][j+1]<<endl;;
          if(i-1>=0 && j+1<M && A[i][j+1]!=-1){
            //cout<<i<<" : "<<j<<A[i-1][j]<<" "<<A[i][j+1]<<endl;
            if(A[i-1][j]>A[i][j+1]){
              //cout<<i<<" "<<j;
              flag=1;
              break;
            }
            else{
              //cout<<i<<" # "<<j<<endl;
              A[i][j]=max(A[i-1][j],A[i][j-1]);
            }
          }
          else if(i-1>=0){
            A[i][j]=max(A[i-1][j],A[i][j-1]);
          }
          else if(i-1<0){
            A[i][j]=A[i][j-1];
          }
          else{
            A[i][j]=A[i-1][j];
          }
        }
      }
    }
    if(flag==1)
      cout<<-1<<endl;
    else{
      for(i=0;i<N;i++){
        for(j=0;j<M;j++){
          cout<<A[i][j]<<" ";
        }
        cout<<endl;
      }
    }
  }
}
