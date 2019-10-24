//ac

#include <bits/stdc++.h>

using namespace std;

int main(){
	long long N,i,j,ans,tmp1,tmp2;
	cin>>N;
	while(N--){
		cin>>tmp1>>tmp2;
		ans=0;
		i=min(tmp1,tmp2);
		j=max(tmp1,tmp2);
		//cout<<floor(log(j)/log(2))<<" "<<floor(log(i)/log(2))<<endl;
		while(floor(log(j)/log(2))!=floor(log(i)/log(2))){
			j/=2;
			ans++;
		}
		while(i!=j){
			//cout<<i<<" "<<j<<" "<<ans<<endl;
			i/=2;
			j/=2;
			ans+=2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
