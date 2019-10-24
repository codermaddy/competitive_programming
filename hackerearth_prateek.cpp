#include <iostream>
using namespace std;

int main()
{
    short T,i,flag;
    long N,j,k;
    long long X,sum;
    long * Cost;
    cin>>T;
    for(i=0;i!=T;i++){
    	cin>>N>>X;
    	Cost = new (nothrow) long [N];
    	for(j=0;j!=N;j++){
    		cin>>Cost[j];
    	}
    	flag=0;
    	for(j=0;j!=N && flag!=1;j++){
    		sum=0,flag=0;
    		for(k=j;k!=N && flag==0;k++){
    			sum=sum+Cost[k];
    			if(sum>X){
    				flag=2;
    			}
    			else if(sum==X){
    				flag=1;
    			}
			cout<<sum<<"\t";
    		}
		cout<<"\n";
    	}
    	if(flag==1){
    		cout<<"YES";
    	}
    	else{
    		cout<<"NO";
    	}
    	cout<<"\n";
    	delete [] Cost;
    }
    return 0;
}

