//ac
//april long '18

#include <bits/stdc++.h>
#define epsilon 0.000001
#define INF 999999999999

using namespace std;

typedef long long ll;

int main(){
  int T,N,S,Y,i;
  int V[11],C[11];
  ll P[11];
  bool D[11];
  double timen,initial_time,final_time,time_chef;
  cin>>T;
  while(T--){
    //entry
    cin>>N>>S>>Y;
    for(i=1;i<=N;i++){
      cin>>V[i];
    }
    for(i=1;i<=N;i++){
      cin>>D[i];
    }
    for(i=1;i<=N;i++){
      cin>>P[i];
    }
    for(i=1;i<=N;i++){
      cin>>C[i];
    }
    timen=0;
    time_chef = Y*1.0/S;
    for(i=1;i<=N;i++){
      //crossing the ith lane
      //calculating time of arrival and departure
      if(D[i]==0){
        if(P[i]<0){
          //cout<<timen;
          timen+=time_chef;
          //cout<<"-->"<<timen<<endl;
          continue;
        }
        else{
          initial_time=abs(P[i])*1.0/V[i];
          final_time=initial_time+C[i]*1.0/V[i];
        }
      }
      else{
        if(P[i]>0){
          //cout<<timen;
          timen+=time_chef;
          //cout<<"-->"<<timen<<endl;
          continue;
        }
        else{
          initial_time=abs(P[i])*1.0/V[i];
          final_time=initial_time+C[i]*1.0/V[i];
        }
      }
      //checking against chef
      if(initial_time-timen-time_chef>epsilon || timen-final_time>epsilon){
        //cout<<timen;
        timen+=time_chef;
        //cout<<"-->"<<timen<<endl;
      }
      else{
        //cout<<timen;
        timen=final_time+time_chef;
        //cout<<"-->"<<timen<<endl;
      }
    }
    cout<<fixed<<setprecision(6)<<timen<<endl;
  }
  return 0;
}
