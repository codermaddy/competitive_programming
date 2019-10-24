//nov 17
#include<iostream>
#include<vector>

//partial

using namespace std;

int max(int a,int b){
	int c=a>b?a:b;
	return c;
}

int main(){
	int T,N,i,na,nb,nx,A,j,ctr;
	char str;
	vector<char> C;
	cin>>T;
	while(T--){
		str='a';
		cin>>N>>A;
		for(i=0;i<A;i++)
			C.push_back(str++);
		if(A>2){
			cout<<1<<" ";
			if(N%A==0)
				na=N/A;
			else
				na=N/A+1;
			ctr=0;
			for(i=0;i<na;i++){
				for(j=0;j<A;j++){
					ctr++;
					if(ctr<=N)
						cout<<C[j];
				}
			}
			cout<<endl;
		}
		else if(A==2){
			nb=(N+1)/3;
			if((N+1)%3==0)
				na=nb;
			else
				na=nb+1;
			nx=(N-na-nb);
			if(nx%2!=0)
				nb++;
			cout<<max(na,nb)<<" ";
			for(i=0;i<na;i++){
				cout<<"a";
			}
			for(i=0;i<nx/2;i++){
				cout<<"ba";
			}
			for(i=0;i<nb;i++){
				cout<<"b";
			}
			cout<<endl;
		}
		else if(A==1){
			cout<<N<<" ";
			for(i=0;i<N;i++){
				cout<<"a";
			}
			cout<<endl;
		}
		C.clear();
	}
	return 0;
}
