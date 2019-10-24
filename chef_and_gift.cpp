//ac

#include <bits/stdc++.h>

using namespace std;

int main(){
	int even,i,tmp,T,N,K;
	cin>>T;
	while(T--){
		even=0;
		cin>>N>>K;
		for(i=0;i<N;i++){
			cin>>tmp;
			if(tmp%2==0)
				even++;
		}
		if(K==0){
			if(even==N)
				cout<<"NO"<<endl;
			else
				cout<<"YES"<<endl;
		}
		else if(even>=K)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
