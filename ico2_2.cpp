#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define INF 999999999
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool prime[100005];

void sieve(int n){
	memset(prime,true,sizeof prime);
	prime[1]=false;
	for(int p=2;p*p<=n;p++){
		if(prime[p]){
			for(int i=2*p;i<=n;i+=p){
				prime[i]=false;
			}
		}
	}
}

ll power(ll x,int y){
	int res=1;
	x=x%MOD;
	while(y>0){
		if (y & 1)
            res = (res*x) % MOD;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % MOD;
	}
	return res;
}

int main(){

	freopen("ico2_2.in","r",stdin);
	freopen("ico2_2.out","w",stdout);

	int i,L,R,T;
	ll pre[100005];
	sieve(100005);
	pre[0]=0;
	for(i=1;i<=100005;i++){
		if(prime[i]){
			pre[i]=pre[i-1]+power(i,i);
			//cout<<i<<" "<<pre[i]<<"\n";
		}
		else
			pre[i]=pre[i-1];
	}
	/*for(i=1;i<=30;i++){
		cout<<i<<" "<<pre[i]<<" \n";
	}*/
	cin>>T;
	while(T--){
		cin>>L>>R;
		ll ans=pre[R]-pre[L-1];
		while(ans<0){
			ans+=MOD;
		}
		cout<<ans%MOD<<"\n";
	}

	return 0;
}