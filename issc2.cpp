#include <bits/stdc++.h>

#define INF 999999999
#define MOD 1000000007
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){

	freopen("issc2.in","r",stdin);
	freopen("issc2.out","w",stdout);

	int i,T,N,M,t;
	ll C[100005],ans;
	priority_queue<pair<int,int> > p;
	cin>>T;
	while(T--){
		cin>>N>>M;
		for(i=0;i<N;i++){
			cin>>C[i];
			p.push(make_pair(-1*C[i],i));
		}
		ans=0;
		for(i=0;i<M;i++){
			ans=-1*p.top().first;
			t=p.top().second;
			p.pop();
			p.push(make_pair(-1*ans-C[t],t));
		}
		cout<<ans<<"\n";
		while(!p.empty()){
			p.pop();
		}
	}


	return 0;
}