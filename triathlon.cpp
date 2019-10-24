#include<bits/stdc++.h>

using namespace std;

int main(){
	int N,i;
	vector <pair<long long,long long> >P;
	long long a,b,c,sum=0,max;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>a>>b>>c;
		P.push_back(make_pair(b+c,a));
	}
	sort(P.rbegin(),P.rend());
	max=P[0].first+P[0].second;
	sum=P[0].second;
	for(i=1;i<N;i++){
		sum+=P[i].second;
		if(sum+P[i].first>max)
			max=sum+P[i].first;
	}
	cout<<max<<endl;
	return 0;
}
