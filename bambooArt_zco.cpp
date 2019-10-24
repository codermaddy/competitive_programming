#include <iostream>

using namespace std;

int main(){
	int assign(char [], long [], long);
	int addspace(char []);
	void del(char []);
	void bubsort(long [], int);
	long size1=20025,diff;
	int num=0,ctr=0,i,j,y=1,x=0,cnt=0;
	double dvsr=0;
	char ar[size1];
	cin.getline(ar,size1);
	long * fin;
	for(i=0;ar[i]!=' ';i++){
		num=num*10+(ar[i]-'0');
	}
	fin=new (nothrow) long [num];
	addspace(ar);
	del(ar);
	assign(ar,fin,size1);
	bubsort(fin,num);
	for(i=0;i!=num-1;i++){
		for(j=i+1;j!=num;j++){
			diff=fin[j]-fin[i];
			ctr=1;
			y=1;
			for(x=i+1;x!=num && ((fin[x]-fin[i])<=diff*y);x++){
				dvsr=diff*y;
				if(((fin[x]-fin[i])/dvsr)==1){
					ctr++;
					y++;
				}
			}
			if(ctr>cnt){
				cnt=ctr;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}

int assign(char ar[],long fin[],long size){
	long i=0,ctr=0,x;
	long num=0;
	for(x=0;ar[x]==' ';x++);
	for(i=x;i!=size;i++){
		if(ar[i]!=' '){		
			num = num*10 + (ar[i] - '0');
		}
		else{
			fin[ctr]=num;
			num=0;
			ctr++;
		}
	}
	return 0;
}

int addspace(char a[]){
	long i;	
	for(i=0;a[i]!='\0';i++);
	a[i]=' ';
	return 0;
}

void bubsort(long x[], int s){
	int i,j;
	long tmp;
	for(i=1;i!=s;i++){
		for(j=i;x[j]<x[j-1] && j!=0;j--){
		    tmp=x[j];
		    x[j]=x[j-1];
		    x[j-1]=tmp;
		}
	}
}
void del(char a[]){
	int i;
	for(i=0;a[i]!=' ';i++){
		a[i]=' ';
	}
}

