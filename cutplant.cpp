//ac
//april long'18

#include <bits/stdc++.h>
#define INF 999999999
using namespace std;

typedef long long ll;
ll res[100005],A[100005],B[100005],kb[100005],ka[100005],kareal[100005],barrier[100005];
bool ans[100005];
vector <pair <ll,int> > sorted;
int N;

int main(){
  int T,i,k,idx,cnt,left,right,now,add;
  ll sum;
  bool flag,flag2;
  cin>>T;
  while(T--){
    cin>>N;
    for(i=0;i<N;i++){
      cin>>A[i];
    }

    for(i=0;i<N;i++){
      cin>>B[i];
      sorted.push_back(make_pair(B[i],i));
      //if(A[i]==B[i])
        //cnt++;
    }
    sort(sorted.begin(),sorted.end());
    //finding k for B[]
    kb[N-1]=N;
    for(i=N-2;i>=0;i--){
      now=i+1;
      while(now<N){
        if(B[i]<B[now]){
          kb[i]=now;
          break;
        }
        else
          now=kb[now];
      }
      if(now>N-1)
        kb[i]=N;
    }
    //finding k' for A[]
    ka[N-1]=N;
    for(i=N-2;i>=0;i--){
      now=i+1;
      while(now<N){
        if(A[i]>A[now]){
          ka[i]=now;
          break;
        }
        else
          now=ka[now];
      }
      if(now>N-1)
        ka[i]=N;
    }
    //finding actual k'
    kareal[N-1]=N;
    for(i=N-2;i>=0;i--){
      now=i+1;
      while(now<N){
        if(B[i]>A[now]){
          kareal[i]=now;
          break;
        }
        else
          now=ka[now];
      }
      if(now>N-1)
        kareal[i]=N;
    }
    //calculating barrier
    flag=0;
    for(i=0;i<N;i++){
      barrier[i]=min(kb[i],kareal[i]);
      if(A[i]<B[i])
        flag=1;
    }
    /*for(i=0;i<N;i++){
      cout<<barrier[i]<<endl;
    }*/
    res[N-1]=N;
    ans[N-1]=0;
    for(i=N-2;i>=0;i--){
      if(B[sorted[i].second]==B[sorted[i+1].second]){
        if(A[sorted[i+1].second]!=B[sorted[i+1].second] && sorted[i+1].second<barrier[sorted[i].second]){
            res[i]=sorted[i+1].second;
            ans[i]=1;
        }
        else if(ans[i+1]==1 && res[i+1]<barrier[sorted[i].second]){
          res[i]=ans[i+1];
          ans[i]=1;
        }
        else{
          ans[i]=0;
          res[i]=N;
        }
      }
      else{
        res[i]=N;
        ans[i]=0;
      }
    }
    /*for(i=0;i<N;i++){
      idx=lower_bound(sorted.begin(),sorted.end(),make_pair(B[i],i))-sorted.begin();
      cout<<ans[idx]<<" "<<res[idx]<<endl;
    }*/
    if(flag==1)
      cout<<-1<<endl;
    else{
      if(N>1000){
        add=0;
        for(i=0;i<N;i++){
          idx=lower_bound(sorted.begin(),sorted.end(),make_pair(B[i],i))-sorted.begin();
          //cout<<i<<" "<<idx<<" "<<barrier[i]<<" "<<add<<endl;
          if(A[i]==B[i])
            add++;
          else{
            if(ans[idx]==1)
              add++;
          }
        }
      }
      else{
        add=0;
        for(i=0;i<N;i++){
          idx=lower_bound(sorted.begin(),sorted.end(),make_pair(B[i],i))-sorted.begin();
          //cout<<i<<" "<<idx<<" "<<barrier[i]<<" "<<add<<endl;
          if(A[i]==B[i])
            add++;
          else{
            k=1;
            while(idx+k<N && sorted[idx+k].first==B[i]){
              if(A[sorted[idx+k].second]!=B[sorted[idx+k].second] && sorted[idx+k].second<barrier[i]){
                //cout<<i<<" ok\n";
                add++;
                break;
              }
              idx++;
            }
          }
        }
      }
      cout<<N-add<<endl;
    }
    sorted.clear();
  }
  return 0;
}
