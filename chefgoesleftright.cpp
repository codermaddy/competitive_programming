//nov. challenge 17
//ac

#include <iostream>
#include <vector>

using namespace std;

int main(){
	int T,N,i,flag;
	vector<long long>A;
	long long tmp,up_limit,low_limit,X;
	cin>>T;
	while(T--){
		cin>>N>>X;
		for(i=0;i<N;i++){
			cin>>tmp;
			A.push_back(tmp);
		}
		up_limit=1000000001;
		low_limit=-1;
		flag=0;
		for(i=0;i<N-1 && flag!=1;i++){
			//cout<<A[i]<<" "<<X<<" "<<up_limit<<" "<<low_limit<<" "<<flag<<endl;
			if(A[i]>X){
				if(A[i]>up_limit){
					flag=1;
				}
				else{
					up_limit=A[i];
				}
			}
			else if(A[i]<X){
				if(A[i]<low_limit){
					flag=1;
				}
				else{
					low_limit=A[i];
				}
			}	
		}
		//cout<<flag<<endl;
		if(flag==1)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
			
		A.clear();	
	}			
	return 0;
}
