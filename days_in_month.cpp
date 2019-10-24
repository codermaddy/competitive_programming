#include<bits/stdc++.h>
#define REP(i,N) for(i=0;i<N;i++)
#define pb push_back

using namespace std;
typedef long long ll;

int day[7];
int W;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T,i,x;
	string S;
	cin>>T;
	while(T--){
		cin>>W;
		cin>>S;
		for(i=0;i<7;i++){
			day[i]=4;
		}
		/*for(i=0;i<7;i++){
			cout<<day[i]<<" ";
		}*/
		if(S=="mon")
			x=0;
		if(S=="tues")
			x=1;
		if(S=="wed")
			x=2;
		if(S=="thurs")
			x=3;
		if(S=="fri")
			x=4;
		if(S=="sat")
			x=5;
		if(S=="sun")
			x=6;
		for(i=29;i<=W;i++){
			day[x]++;
			x=(x+1)%7;
		}
		for(i=0;i<7;i++){
			cout<<day[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}