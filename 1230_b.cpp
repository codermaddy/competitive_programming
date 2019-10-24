#include <bits/stdc++.h>

#define INF 999999999
#define MOD 1000000007
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
	string S;
	int n, k;
	cin>>n>>k;
	cin>>S;
	if(n==1 && k>=1){
		S[0] = '0';
		k--;
	}
	else if(n>1 && k>=1 && S[0]!='1'){
		S[0] = '1';
		k--;
	}
	for(int i=1;i<S.size() && k>0;i++){
		if(S[i]!='0'){
			S[i] = '0';
			k--;
		}
	}
	cout<<S<<"\n";
	return 0;
}