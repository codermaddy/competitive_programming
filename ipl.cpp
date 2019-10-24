//zco
//ac

#include<iostream>
#include<vector>

#define MAXN 200001

using namespace std;

long long max(long long a,long long b,long long c){
	long long d;
	d=a>b?(a>c?a:c):(b>c?b:c);
	return d;	
}

void initialize(long long A[]){
	for(int i=0;i<MAXN;i++){
		A[i]=-1;
	}
}

long long rec(vector<int> &A,long long sum[],int i){
	if(sum[i]!=-1){
		return sum[i];
	}
	else{
		if(i==0){
			sum[i]=A[i];
		}
		else if(i==1){
			sum[i]=rec(A,sum,0)+A[i];
		}
		else if(i==2){
			sum[i]=max(rec(A,sum,0)+A[2],A[1]+A[2],rec(A,sum,1));
		}
		else{
			sum[i]=max(rec(A,sum,i-1),rec(A,sum,i-2)+A[i],rec(A,sum,i-3)+A[i]+A[i-1]);
		}
		return sum[i];
	}
}

int main(){
	int i,N,tmp;
	vector<int> A;
	long long arr[MAXN];
	initialize(arr);
	cin>>N;
	for(i=0;i<N;i++){
		cin>>tmp;
		A.push_back(tmp);
	}
	cout<<rec(A,arr,N-1)<<endl;
	return 0;
}
