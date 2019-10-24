#include <iostream>

using namespace std;

int main(){

	freopen("comb_prob.out","w",stdout);

	int i,j,k,l,cnt=0,cnt2=0;
	for(i=1;i<=9;i++){
		for(j=0;j<=9;j++){
			for(k=0;k<=9;k++){
				for(l=0;l<=9;l++){
					if(i!=j && i!=k && i!=l && j!=k && j!=l && k!=l && l%2==0){
						cnt++;
					}
					if(i!=j && i!=k && i!=l && j!=k){
						cnt2++;
					}
				}
			}
		}
	}
	cout<<cnt<<"\n"<<cnt2<<"\n";
	return 0;
}