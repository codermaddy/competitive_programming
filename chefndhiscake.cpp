//dec 17 
//ac

#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T,N,M,i,j,sum1,sum2;
	char A[101][101];
	cin>>T;
	while(T--){
		cin>>N>>M;
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				cin>>A[i][j];
			}
		}
		//config 1(start with red)
		sum1=0;
		sum2=0;
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				if((i+j)%2==0 && A[i][j]=='G')
					sum1+=3;
				else if((i+j)%2==1 && A[i][j]=='R')
					sum1+=5;
			}
		}
		//config 2(start with green)
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				if((i+j)%2==1 && A[i][j]=='G')
					sum2+=3;
				else if((i+j)%2==0 && A[i][j]=='R')
					sum2+=5;
			}
		}
		cout<<min(sum1,sum2)<<endl;
	}
	return 0;
}
