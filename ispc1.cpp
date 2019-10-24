#include <bits/stdc++.h>

#define INF 999999999
#define MOD 1000000007
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull gcd(ll a,ll b){
	if (b == 0) 
        return a; 
    return gcd(b, a % b); 
}

int main(){

	freopen("ispc1.in","r",stdin);
	freopen("ispc1.out","w",stdout);

	ll T,i,j,N,ar[105];
	ull L;
	//ull x;
	cin>>T;
	while(T--){
		cin>>N;
		for(i=0;i<N;i++){
			cin>>ar[i];
		}
		sort(ar,ar+N);
		L=ar[0];
		for(i=1;i<N;i++){
			L=(ar[i])*(L/gcd(L,ar[i]));
		}
		for(i=0;i<N;i++){
			if(L==ar[i]){
				L*=2;
				break;
			}
		}
		cout<<L<<"\n";
	}
	return 0;
}