//ac
//april long '18

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
  int T,i,y,length,tmp1,tmp2,num,den;
  char S[1005];
  ll N;
  ull ans;
  int ct_a[1005],ct_b[1005];
  cin>>T;
  while(T--){
    ans=0;
    cin>>S>>N;
    if(S[0]=='a'){
      ct_a[0]=1;
      ct_b[0]=0;
    }
    else{
      ct_b[0]=1;
      ct_a[0]=0;
    }
    for(i=1;S[i]!='\0';i++){
      if(S[i]=='a'){
        ct_a[i]=ct_a[i-1]+1;
        ct_b[i]=ct_b[i-1];
      }
      else{
        ct_b[i]=ct_b[i-1]+1;
        ct_a[i]=ct_a[i-1];
      }
    }
    length=i;
    //cout<<length<<endl;
    for(y=0;S[y]!='\0';y++){
      num=ct_b[y]-ct_a[y];
      den=ct_a[length-1]-ct_b[length-1];
      if(den>0){
        if(num>=0){
          tmp1=num/den + 1;
          if(N-tmp1>0)
            ans+=N-tmp1;
        }
        else{
          tmp1=0;
          if(N-tmp1>0)
            ans+=N-tmp1;
        }
      }
      else if(den<0){
        if(num>=0){
          ans+=0;
        }
        else{
          if(num%den!=0)
            tmp1=num/den + 1;
          else
            tmp1=num/den;
          if(tmp1>N)
            ans+=N;
          else
            ans+=tmp1;
        }
      }
      else{
        if(num>=0)
          ans+=0;
        else
          ans+=N;
      }
      //cout<<y<<" "<<ans<<"\n";
    }
    cout<<ans<<endl;
  }
  return 0;
}
