#include <bits/stdc++.h>

#define INF 999999999
#define MOD 1000000007
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){

	freopen("issc3.in","r",stdin);
	freopen("issc3.out","w",stdout);

	ll cnt,i,j,N,M,x,l,r;
	ll val[100005];
	ll upd[100005];
	memset(val,0,sizeof val);
	cin>>N>>M;
	for(i=0;i<M;i++){
		cin>>x>>l>>r;
		val[l]+=x;
		val[r+1]-=x;
	}
	ll start=0;
	for(i=1;i<=N;i++){
		start+=val[i];
		upd[i]=start;
		cout<<i<<" "<<val[i]<<" "<<start<<" "<<upd[i]<<"\n";
	}
	ll maxi=-999999999;
	for(i=1;i<=N;i++){
		maxi=max(maxi,upd[i]);
	}
	cnt=0;
	for(i=1;i<=N;i++){
		if(upd[i]==maxi)
			cnt++;
	}
	cout<<cnt<<"\n";
	for(i=1;i<=N;i++){
		if(upd[i]==maxi)
			cout<<i<<" ";
	}
	cout<<"\n";
	return 0;
}