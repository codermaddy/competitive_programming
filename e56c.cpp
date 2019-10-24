#include <bits/stdc++.h>

using namespace std;

int main(){

	//freopen("e56c.in","r",stdin);
	//freopen("e56c.out","w",stdout);

	int N,i;
	long long a[200005],b[200005],left,right;
	cin>>N;
	for(i=1;i<=N/2;i++){
		cin>>b[i];
	}
	left=0;
	right=b[1];
	for(i=1;i<=N/2;i++){
		//1st try
		if(b[i]-left<=right && b[i]-left>=0){
			a[i]=left;
			a[N-i+1]=b[i]-left;
			right=b[i]-left;
		}
		//2nd try
		else if(b[i]-right>=left && b[i]-right>=0){
			a[i]=b[i]-right;
			a[N-i+1]=right;
			left=b[i]-right;
		}
	}
	for(i=1;i<=N;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	return 0;
}