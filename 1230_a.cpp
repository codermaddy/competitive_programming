#include <bits/stdc++.h>

#define INF 999999999
#define MOD 1000000007
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
	int a[4];
	for(int i=0;i<4;i++){
		cin>>a[i];
	}
	int flag = 0;
	//1 and 3
	if(a[0] == a[1]+a[2]+a[3] || a[1] == a[0]+a[2]+a[3] || a[2] == a[0]+a[1]+a[3] || a[3] == a[0]+a[1]+a[2])
		flag = 1;
	//2 and 2
	if(a[0]+a[1] == a[2]+a[3] || a[0]+a[2] == a[1]+a[3] || a[0]+a[3] == a[1]+a[2])
		flag = 1;
	if(flag)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}