//ac
//may long'18

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
vector <pair <ll,int> > sorted;
vector <ll> a;

void swaps(ll a,ll b){
  ll tmp=a;
  a=b;
  b=tmp;
}

int real_bsearch(ll key){
  int l=1;
  int h=n;
  int m;
  while(l<=h){
    m=(l+h)/2;
    if(sorted[m].first==key)
      return m;
    else if(sorted[m].first>key)
      h=m-1;
    else
      l=m+1;
  }
  return -1;
}

int b_search(ll x){
  int idx=real_bsearch(x);
  int real_idx=sorted[idx].second;
  int low=1,mid,l_swap=0,r_swap=0,l_ok=0,r_ok=0;
  int high=n;
  int less=idx-1;
  int great=n-idx;
  //cout<<"== "<<x<<" "<<idx<<"\n";
  while(low<=high){
    mid=(low+high)/2;
    //cout<<x<<" "<<real_idx<<" "<<low<<" "<<high<<" "<<mid<<" "<<l_idx<<" "<<r_idx<<" "<<swap<<"\n";
    if(a[mid]==x)
      break;
    else if(a[mid]<x && mid<real_idx){
      l_ok++;
    }
    else if(a[mid]>x && mid>real_idx){
      r_ok++;
    }
    else if(a[mid]<x && mid>real_idx){
      l_swap++;
    }
    else if(a[mid]>x && mid<real_idx){
      r_swap++;
    }
    if(mid>real_idx)
      high=mid-1;
    else
      low=mid+1;
  }
  if(r_swap+l_ok>less || l_swap+r_ok>great)
    return -1;
  else
    return max(l_swap,r_swap);
}

int main(){
  int T,i,q;
  ll tmp;
  cin>>T;
  while(T--){
    cin>>n>>q;
    a.push_back(0);
    sorted.push_back(make_pair(0,0));
    for(i=0;i<n;i++){
      cin>>tmp;
      a.push_back(tmp);
      sorted.push_back(make_pair(tmp,i+1));
    }
    sort(sorted.begin(),sorted.end());
    /*for(i=0;i<=n;i++){
      cout<<sorted[i].first<<" "<<sorted[i].second<<"\n";
    }*/
    while(q--){
      cin>>tmp;
      cout<<b_search(tmp)<<"\n";
    }
    a.clear();
    sorted.clear();
  }
  return 0;
}
