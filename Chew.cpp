//zco
//ac

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long find(const vector<long long> &Arr,long long i,long long x,long long N){
	long long u=i+1;
	long long v=N-1;
	long long m;
	while(u<=v){
		m=(u+v)/2;
		if(Arr[m-1]<x && Arr[m]>=x){
			//cout<<"sending "<<i<<" "<<m<<endl;
			return m;
		}
		else if(Arr[m-1]<x && Arr[m]<x)
			u=m+1;
		else
			v=m-1;
	}
	return -1;
}

int main(){
	long long N,K,i,tmp,u,v,m,ct=0,ret;
	vector<long long> A;
	cin>>N>>K;
	for(i=0;i<N;i++){
		cin>>tmp;
		A.push_back(tmp);
	}
	sort(A.begin(),A.end());
	for(i=0;A[i]<K && i<N-1;i++){
		tmp=K-A[i];
		ret=find(A,i,tmp,N);
		//cout<<ret-i-1<<" "<<ret<<endl;
		if(ret-i-1>=0)
			ct+=ret-i-1;
		else if(ret-i-1<=0 && A[i]+A[N-1]<K)
			ct+=N-i-1;
	}
	cout<<ct<<endl;
	return 0;
}
