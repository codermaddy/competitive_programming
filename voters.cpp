//voters(easy)
//ac

#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N1,N2,N3,i;
	long long tmp,num;
	vector<long long> A;
	vector<long long> B;
	cin>>N1>>N2>>N3;
	for(i=0;i<N1+N2+N3;i++){
		cin>>tmp;
		A.push_back(tmp);
	}
	sort(A.begin(),A.end());
	for(i=0;i<N1+N2+N3-1;i++){
		if(A[i]==A[i+1] && A[i]!=num){
			B.push_back(A[i]);
		}
		num=A[i];
	}
	cout<<B.size()<<endl;
	for(i=0;i<B.size();i++){
		cout<<B[i]<<endl;
	}	
	return 0;
}
