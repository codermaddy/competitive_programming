//horses(easy)
//ac

#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N,T,i;
	long long tmp,diff=1000000001;
	vector<long long> A;
	cin>>T;
	while(T--){
		diff=1000000001;
		cin>>N;
		for(i=0;i<N;i++){
			cin>>tmp;
			A.push_back(tmp);
		}
		sort(A.begin(),A.end());
		for(i=0;i<N-1;i++){
			tmp=A[i+1]-A[i];
			if(diff>tmp)
				diff=tmp;
		}
		cout<<diff<<endl;
		A.clear();
	}
	return 0;
}
