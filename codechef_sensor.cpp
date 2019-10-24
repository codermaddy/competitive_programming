#include <iostream>

using namespace std;

typedef long long ll;

void merge(ll A[], int f, int m, int l){
	int x=0,i=0,y=0;
	int p = m-f+1;
	int q = l-m;
	int r = p+q;
	ll * B;
	ll * C;
	ll * D;
	D=new ll [r];
	B=new ll [p];
	C=new ll [q];
	for(i=f;i<=m;i++){
		B[x++]=A[i];
	}
	for(i=m+1;i<=l;i++){
		C[y++]=A[i];
	}
	x=0;
	y=0;
	for(i=0;i<r;i++){
		if(B[x]<C[y]){
			D[i]=B[x];
			B[x]=1000000001;
			x++;
		}
		else{
			D[i]=C[y];
			C[y]=1000000001;
			y++;
		}
		if(x==p){
			x--;
		}
		if(y==q){
			y--;
		}
	}
	for(i=0;i!=r;i++){
		A[f++]=D[i];
		//cout<<D[i]<<"\t";
	}
	//cout<<endl;
	delete [] B;
	delete [] C;
	delete [] D;
}

void merge_sort (ll A[ ] , int start , int end ) {
    if( start < end ) {
       int mid = (start + end ) / 2 ;           // defines the current array in 2 parts .
      // cout<<start<<" "<<mid<<" "<<end<<endl;
       merge_sort (A, start , mid ) ;                 // sort the 1st part of array .
       merge_sort (A,mid+1 , end ) ;              // sort the 2nd part of array.

     // merge the both parts by comparing elements of both the parts.
        merge(A,start , mid , end ); 
	
	}  
}    

ll LCM(ll a, ll b){
	ll l,i,g,ret,tmp;
	int flag=0;
	if(a>b){
		g=a;
		l=b;
	}
	else if(b>a){
		g=b;
		l=a;
	}
	else{
		return a;
	}
	for(i=1;flag!=1;i++){
		tmp=g*i;
		if(tmp%l==0){
			flag=1;
			ret=tmp;
		}
	}
	return ret;		
}

int main(){
	int T,i,N,j,flag=0,k;
	ll * A;
	ll tmp,tmpo;
	cin>>T;
	for(i=0;i!=T;i++){
		cin>>N;
		A = new ll [N];
		for(j=0;j!=N;j++){
			cin>>A[j];
		}
		tmp=99999999000000001;
		merge_sort(A,0,N-1);
		/*for(j=0;j!=N;j++){
			cout<<A[j]<<"\t";
		}
		cout<<"\n";*/
		for(j=0;j<N-1;j++){
			flag=0;
			for(k=j+1;k<N;k++){
				tmpo=LCM(A[j],A[k]);
				//cout<<tmpo<<"\t";
				if(tmpo<tmp){
					tmp=tmpo;
				}
			}
			//cout<<"\n\n";
		}
		cout<<tmp<<endl;
		delete [] A;
	}
	return 0;
}
