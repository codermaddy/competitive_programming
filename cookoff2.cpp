//cookoff nov. '17
//ac

#include <bits/stdc++.h>

using namespace std;

int main(){
	int T,N,i,j,tmp,mini,maxi,Timei,isRatedi,colori,tmp2,mini2,maxi2,Timei2,isRatedi2,colori2,flag;
	char A[20],B[20];
	deque <int> I,min,max,Time,isRated,color;
	cin>>T;
	while(T--){
		cin>>N;
		for(i=0;i<N;i++){
			cin>>tmp>>mini>>maxi>>Timei>>A>>B;
			I.push_back(tmp);
			min.push_back(mini);
			max.push_back(maxi);
			Time.push_back(Timei);
			if(A[0]=='r')
				isRated.push_back(1);
			else
				isRated.push_back(0);
			if(B[0]=='w')
				color.push_back(1);
			else if(B[0]=='b')
				color.push_back(2);
			else
				color.push_back(3);
		}
		cout<<"wait"<<endl;
		for(i=1;i<N;i++){
			flag=0;
			tmp=I[i];
			mini=min[i];
			maxi=max[i];
			Timei=Time[i];
			isRatedi=isRated[i];
			colori=color[i];
			for(j=0;j<i && flag!=1;j++){
				tmp2=I[j];
				mini2=min[j];
				maxi2=max[j];
				Timei2=Time[j];
				isRatedi2=isRated[j];
				colori2=color[j];
				if(tmp2>=mini && tmp>=mini2 && tmp2 <=maxi && tmp<=maxi2 && Timei==Timei2 && isRatedi==isRatedi2 && ((colori!=colori2 && colori!=3 && colori2!=3 ) || (colori==3 && colori2==3))){
					cout<<j+1<<endl;
					flag=1;
					I[i]=-1;
					min[i]=9999999;
					max[i]=-1;
					Time[i]=-1;
					isRated[i]=-1;
					color[i]=-1;
					I[j]=-1;
					min[j]=9999999;
					max[j]=-1;
					Time[j]=-1;
					isRated[j]=-1;
					color[j]=-1;
				}
				/*else{
					cout<<"Nah"<<i<<" "<<j<<endl;
					cout<<I[i]<<" "<<I[j]<<endl;
					cout<<min[i]<<" "<<min[j]<<endl;
					cout<<max[i]<<" "<<max[j]<<endl;
					cout<<Time[i]<<" "<<Time[j]<<endl;
					cout<<isRated[i]<<" "<<isRated[j]<<endl;
					cout<<color[i]<<" "<<color[j]<<endl;
				}*/
			}
			if(flag==0)
				cout<<"wait"<<endl;
		}
		I.clear();
		min.clear();
		max.clear();
		Time.clear();
		isRated.clear();
		color.clear();
	}
	return 0;
}
