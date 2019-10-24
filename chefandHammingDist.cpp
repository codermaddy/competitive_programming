#include<bits/stdc++.h>

using namespace std;

void single_swap(vector<int> &X,int size){
	int i;
	for(i=0;i<size-1;i+=2){
		swap(X[i],X[i+1]);
	}
}

void double_swap(vector<int> &X,int size){
	int i;
	for(i=2;i<size-1;i++){
		if(X[i]==X[i+1]){
			swap(X[i],X[i-2]);
			swap(X[i+1],X[i-1]);
		}
	}
}

void cross_check(vector<int> &X,const vector<int> &Y,int size){
	int i,j=0;
	for(i=0;i<size;i++){
		if(X[i]==Y[i]){
			if(X[i]!=X[j]){
				swap(X[i],X[j]);
			}
			else{
				swap(X[i],X[j+1]);
			}
			j++;
		}
	}
}

int main(){
	int T;
	int N,tmp,i,freq,count;
	vector <int> A,B;
	cin>>T;
	while(T--){
		cin>>N;
		for(i=0;i<N;i++){
			cin>>tmp;
			A.push_back(tmp);
			B.push_back(tmp);
		}
		sort(B.begin(),B.end());
		freq=0;
		for(i=0;i<N-1;i++){
			if(B[i]==B[i+1]){
				freq=1;
				//cout<<B[i]<<" "<<B[i+1];
				break;
			}
		}
		for(i=0;i<N;i++){
			B[i]=A[i];
		}
		if(N!=1 && freq==0){
			cout<<N<<endl;
			cout<<A[N-1]<<" ";
			for(i=0;i<N-1;i++){
				cout<<A[i]<<" ";
			}
		}
		else if(N==1){
			cout<<0<<endl;
			cout<<A[0];
		}
		else{
			count=N;
			single_swap(A,N);
			double_swap(A,N);
			cross_check(A,B,N);
			for(i=0;i<N;i++){
				if(A[i]==B[i]){
					count--;
				}
			}
			cout<<count<<endl;
			for(i=0;i<N;i++){
				cout<<A[i]<<" ";
			}
		}
		cout<<endl;
		A.clear();
		B.clear();
	}
	return 0;
}
