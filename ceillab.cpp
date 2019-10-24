//ceila-b(easy)
//ac

#include<iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int A,B,N;
	cin>>A>>B;
	N=A-B;
	if(N%10!=9)
		cout<<N+1<<endl;
	else if(N%10==9)
		cout<<N-1<<endl;	
	return 0;
}
