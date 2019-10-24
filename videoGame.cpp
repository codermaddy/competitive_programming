//zco
//ac

#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<long long> C;
	vector<int> command;
	int N,pos,tmps,lift,i,H;
	long long tmp;
	cin>>N>>H;
	for(i=0;i<N;i++){
		cin>>tmp;
		C.push_back(tmp);
	}
	do{
		cin>>tmps;
		command.push_back(tmps);
	}while(tmps);
	pos=0;
	lift=0;
	for(i=0;i<command.size() && command[i]!=0;i++){
		switch(command[i]){
			case 1: if(pos>0)
					pos--;
				break;
			case 2:	if(pos<N-1)
					pos++;
				break;
			case 3: if(lift==0 && C[pos]>0){
					C[pos]--;
					lift=1;
				}
				break;
			case 4: if(C[pos]<H && lift==1){
					C[pos]++;
					lift=0;
				}
				break;

		}
	}
	for(i=0;i<N;i++){
		cout<<C[i]<<" ";
	}
	cout<<endl;
	return 0;
}

