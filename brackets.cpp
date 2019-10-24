#include<bits/stdc++.h>
#define MINV -100000000

using namespace std;
typedef long long ll;

int n,k;
stack<int> S;
vector<int> V;
vector<int> B;
ll dp[705][2];
bool vis[705][2];

ll maxSum(int i,bool state){
	if(i==n-1 && state==0)
		return 0;
	if(i==n-1 && state==1){
		if(B[i]<=k)
			return MINV;
		if(S.empty())
			return MINV;
		if(B[i]>k && B[i]-S.top()!=k)
			return MINV;
		if(B[i]>k && B[i]-S.top()==k)
			return V[n-1];
	}
	if(vis[i][state])
		return dp[i][state];
	vis[i][state]=1;
	if(state==0){
		dp[i][state]=max(maxSum(i+1,0),maxSum(i+1,1));
	}
	else{
		if(!S.empty()){
			if(B[i]>k && B[i]-S.top()!=k)
				return MINV;
			else if(B[i]>k && B[i]-S.top()==k){
				S.pop();
				dp[i][state]=max(maxSum(i+1,0),maxSum(i+1,1))+V[i];
				S.push(B[i]);
			}
			else if(B[i]<=k){
				S.push(B[i]);
				dp[i][state]=max(maxSum(i+1,0),maxSum(i+1,1))+V[i];
				S.pop();
			}
		}
		else{
			if(B[i]>k)
				return MINV;
			else if(B[i]<=k){
				S.push(B[i]);
				dp[i][state]=max(maxSum(i+1,0),maxSum(i+1,1))+V[i];
				S.pop();
			}
		}
		return dp[i][state];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i,j;
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>j;
		V.push_back(j);
	}
	for(i=0;i<n;i++){
		cin>>j;
		B.push_back(j);
	}
	memset(vis,0,sizeof vis);
	cout<<max(maxSum(0,0),maxSum(0,1))<<endl;
	for(i=0;i<n;i++){
		cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
	}
	return 0;
}
