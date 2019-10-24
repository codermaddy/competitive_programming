// Insertion Sort - Descending Order

#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	int w;
	int * ar;
	cout<<"How many entries do you have? ";
	cin>>size;
	ar = new (nothrow) int [size];
	if(ar==0){
		cout<<"Error: Couldn't assign memory";
	}
	else{
		int i,j,tmp;
		for(i=0;i!=size;i++){
			cin>>ar[i];
		}
		cout<<"\n";
		for(i=1;i!=size;i++){
			for(j=i;j!=0;j--){
				if(ar[j]>ar[j-1]){
					tmp=ar[j-1];
					ar[j-1]=ar[j];
					ar[j]=tmp;
				}
			}
		}
		for(i=0;i!=size;i++){
			cout<<ar[i]<<"\t";
		}
		cout<<endl;
	}
	return 0;
}
