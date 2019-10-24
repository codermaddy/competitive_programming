//ac
//zco

#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N,K,i,flag=0,j;
	long long tmp,skew,max1,tmp1=999999999,tmp2=999999999,max2;
	vector<long long> A;
	vector<long long> B;
	vector<long long> C;
	vector<long long> D;
	cin>>N>>K;
	for(i=0;i<N;i++){
		cin>>tmp;
		A.push_back(tmp);
		C.push_back(tmp);
	}
	for(i=0;i<N;i++){
		cin>>tmp;
		B.push_back(tmp);
		D.push_back(tmp);
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	sort(C.begin(),C.end());
	sort(D.begin(),D.end());
	/*for(i=0;i<N;i++){
		cout<<A[i]<<" "<<B[i]<<" "<<C[i]<<" "<<D[i]<<endl;
	}*/
	skew=A[N-1]+B[N-1];
	//cout<<skew<<" "<<flag<<endl;
	for(i=0;i<K && i!=N-1;i++){
		swap(A[0],B[N-1]);
		//cout<<"swapping.."<<A[i]<<" "<<B[N-1]<<endl;
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		tmp=A[N-1]+B[N-1];
		if(tmp1>tmp)
			tmp1=tmp;
		//cout<<tmp1<<" "<<tmp<<endl;
	}
	for(i=0;i<K && i!=N-1;i++){
		swap(D[0],C[N-1]);
		//cout<<"swapping.."<<D[i]<<" "<<C[N-1]<<endl;
		sort(D.begin(),D.end());
		sort(C.begin(),C.end());
		tmp=D[N-1]+C[N-1];
		if(tmp2>tmp)
			tmp2=tmp;
		//cout<<tmp2<<" "<<tmp<<endl;
	}
	//cout<<tmp1<<" "<<tmp2<<endl;
	cout<<min(tmp1,min(tmp2,skew))<<endl;
	return 0;
}
