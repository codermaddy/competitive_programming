#include<bits/stdc++.h>
#define REP(i,N) for(i=0;i<N;i++)
#define pb push_back

using namespace std;
typedef long long ll;

vector<ll> A;
int N;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i,T,t1,t2;
	ll tmp;
	string s,t1s="",t2s="";
	cin>>T;
	while(T--){
		t1=0;
		t2=0;
		t1s="";
		t2s="";
		cin>>N;
		REP(i,N){
			cin>>s;
			if(t1s=="" &&t2s==""){
				t1s=s;
				t1++;
			}
			else if(t1s!="" && t2s=="" && s!=t1s){
				t2s=s;
				t2++;
			}
			else if(s==t1s)
				t1++;
			else if(s==t2s)
				t2++;
		}
		if(t1==t2)
			cout<<"Draw"<<endl;
		else if(t1>t2)
			cout<<t1s<<endl;
		else
			cout<<t2s<<endl;
		//cout<<t1<< " "<<t2<<" "<<t1s<<" "<<t2s<<endl;
		A.clear();
	}
	return 0;
}