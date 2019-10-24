#include <iostream>
using namespace std;

int main()
{
	int n,i,j,c1,c2,x,tmp,k;
	cin>>n;
	int ** fin = new (nothrow) int* [n];
	int ** fin2 = new (nothrow) int* [n];
	for(i=0;i!=n;i++){
		fin[i] = new (nothrow) int [n];
		fin2[i] = new (nothrow) int [n];
	}
	cin>>c1>>c2;
	int * X = new (nothrow) int [c1];
	int * Y = new (nothrow) int [c2];
	for(i=0;i!=n;i++){
		for(j=0;j!=n;j++){
			cin>>fin[i][j];
			fin2[i][j] = fin[i][j];
		}
	}
	for(i=0;i!=n;i++){
		for(j=0;j!=n;j++){
			cout<<fin[i][j]<<"\t"<<fin2[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"\n";
	for(i=0;i!=n;i++){
		//sorting begins
		for(j=1;j!=n;j++){
			for(k=j;k!=0;k--){
				if(fin[i][k]<fin[i][k-1]){
					tmp=fin[i][k-1];
					fin[i][k-1]=fin[i][k];
					fin[i][k]=tmp;
				}
			}
		}
		//sorting finishes
		for(j=0;j!=c1-1;j++){
			for(k=j;k!=c1;k++){
				sum=sum+fin[i][k]+fin[i][j];
			
	}
	for(i=0;i!=n;i++){
		for(j=0;j!=n;j++){
			cout<<fin[i][j]<<"\t";
		}
		cout<<endl;
	}
	return 0;
}

