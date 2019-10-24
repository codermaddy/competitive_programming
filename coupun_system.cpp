//ac

#include <bits/stdc++.h>

using namespace std;

int main(){
	int T,N,max_1,max_2,max_3,city_1,city_2,city_3,i,c,l,x;
	cin>>T;
	while(T--){
		max_1=0;
		max_2=0;
		max_3=0;
		city_1=0;
		city_2=0;
		city_3=0;
		cin>>N;
		for(i=0;i<N;i++){
			cin>>c>>l>>x;
			if(l==1 && (x>max_1 || (x==max_1 && c<city_1))){
				max_1=x;
				city_1=c;
			}
			if(l==2 && (x>max_2 || (x==max_2 && c<city_2))){
				max_2=x;
				city_2=c;
			}
			else if(l==3 && (x>max_3 || (x==max_3 && c<city_3))){
				max_3=x;
				city_3=c;
			}
		}
		cout<<max_1<<" "<<city_1<<endl;
		cout<<max_2<<" "<<city_2<<endl;
		cout<<max_3<<" "<<city_3<<endl;
	}
	return 0;
}