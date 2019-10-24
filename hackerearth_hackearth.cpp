#include <iostream>
using namespace std;

int main()
{
    int i,h=0,a=0,c=0,k=0,e=0,r=0,t=0,j,tmp,dis,mini;
    char * ar;
    long N;
    cin>>N;
    long Nx= N+1;
    ar = new (nothrow) char [Nx];
    cin>>ar;
    for(i=0;i!=Nx;i++){
    	if(ar[i]=='h'){
    		h++;
    	}
    	else if(ar[i]=='a'){
    		a++;
    	}
    	else if(ar[i]=='c'){
    		c=c+2;
    	}
    	else if(ar[i]=='k'){
    		k=k+2;
    	}
    	else if(ar[i]=='e'){
    		e++;
    	}
    	else if(ar[i]=='r'){
    		r++;
    	}
    	else if(ar[i]=='t'){
    		t=t+2;
    	}
    }
    long chr[7];
    chr[0]=h;
    chr[1]=a;
    chr[2]=c;
    chr[3]=k;
    chr[4]=e;
    chr[5]=r;
    chr[6]=t;
    for(i=0;i!=7;i++){
    	for(j=i;j!=0;j--){
			if(chr[j]<chr[j-1]){
				tmp=chr[j-1];
				chr[j-1]=chr[j];
				chr[j]=tmp;
			}
    	}
	}
    mini = chr[0];
    if(mini%2==0){
    	dis=mini/2;
    }
    else{
    	dis=(mini-1)/2;
    }
    cout<<dis;
    return 0;
}

