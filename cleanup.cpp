//cleanup(easy)
//ac

#include<bits/stdc++.h>

using namespace std;

int main(){
	int T,tmp,n,m,i;
	vector <int> A;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=0;i<n;i++){
			A.push_back(i+1);
		}
		for(i=0;i<m;i++){
			cin>>tmp;
			A[tmp-1]=n+1;
		}
		sort(A.begin(),A.end());
		/*for(i=0;i<n;i++)
			cout<<A[i]<<" ";*/
		for(i=0;i<n && A[i]<n+1;i+=2){
			cout<<A[i]<<" ";
		}
		cout<<endl;
		for(i=1;i<n && A[i]<n+1;i+=2){
			cout<<A[i]<<" ";
		}
		A.clear();
		cout<<endl;
	}
	return 0;
}
