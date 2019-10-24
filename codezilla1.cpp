#include <bits/stdc++.h>

#define pb push_back
#define INF 999999999
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
	ll K,n,tmp;
	vector<ll> A,pre;
	cin>>n>>K;
	for(int i=0;i<n;i++){
		cin>>tmp;
		A.pb(tmp);
	}
	pre.pb(A[0]);
	for(int i=1;i<n;i++){
		pre.pb(pre[i-1]+A[i]);
	}
	ll mini = INF;
	for(int i=0;i<n;i++){
		int lid = lower_bound(pre.begin()+i,pre.end(),K+pre[i]-A[i])-pre.begin();
		int gid = upper_bound(pre.begin()+i,pre.end(),K+pre[i]-A[i])-pre.begin();
		//cout<<lid<<" "<<gid<<" "<<mini<<"\n";
		if(lid <= n && lid >= 0 && gid <= n && gid >= 0){
			if(gid != lid){
				mini = 0;
				break;
			}
			else{
				lid--;
				mini = min(mini, abs(K-(pre[lid]-pre[i]+A[i])));
				mini = min(mini, abs(K-(pre[gid]-pre[i]+A[i])));
			}
		}
	}
	cout<<mini<<"\n";
	return 0;
}