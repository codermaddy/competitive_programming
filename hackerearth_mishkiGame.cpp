#include <iostream>
using namespace std;

struct intv{
	long l;
	long r;
};

int main()
{
    long N,Q,i,j,x,z;
    long * st;
    long * st2;
    cin>>N>>Q;
    st = new (nothrow) long [N];
    st2 = new (nothrow) long [N];
    for(i=0;i!=N;i++){
    	cin>>st[i];
    }
    for(i=0;i!=N;i++){
    	st2[i]=st[i];
    }
    intv * pointer = new intv [Q];
    for(i=0;i!=Q;i++){
    	cin>>pointer[i].l>>pointer[i].r;
    }
    for(i=0;i!=Q;i++){
	x=0;
    	for(j=pointer[i].l;j<=pointer[i].r;){
    		if(st[j-1]>1){
    			st[j-1]=st[j-1]/2;
    		}
    		else{
    			st[j-1]=0;
				j++;
		}
			x++;
    	}
    	if(x%2==0){
    		cout<<"Hacker"<<endl;
    	}
    	else{
    		cout<<"Mishki"<<endl;
    	}
    	for(z=0;z!=N;z++){
    		st[z]=st2[z];
	 }
    }
    delete [] pointer;
    delete [] st;
    return 0;
}

