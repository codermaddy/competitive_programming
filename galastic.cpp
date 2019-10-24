//ac

#include <bits/stdc++.h>
#define pb push_back
#define INF 999999

using namespace std;

typedef long long ll;

vector <int> adj[100005];
bool vis[100005];
int comp[100005];
int wt[100005];

int dfs(int v,int mini){
	vis[v]=1;
	if(wt[v]>=0)
		mini=min(mini,wt[v]);
	for(int i=0;i<adj[v].size();i++){
		if(!vis[adj[v][i]])
			mini=dfs(adj[v][i],mini);
	}
	return mini;
}

int main(){
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	//this can be opted out if you want to print the output to the sublime console
    	freopen("output.txt", "w", stdout);
	#endif

	int N,M,i,a,b,c=0;
	bool flag=0;
	ll sum=0;
	cin>>N>>M;
	for(i=0;i<M;i++){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for(i=1;i<=N;i++){
		cin>>wt[i];
	}
	memset(vis,0,sizeof vis);
	for(i=1;i<=N;i++){
		if(!vis[i]){
			a=dfs(i,INF);
			if(a==INF){
				flag=1;
			}
			comp[c++]=a;
		}
	}
	//cout<<c<<" ";
	if(flag && c>1)
		cout<<-1<<"\n";
	else if(c==1)
		cout<<0<<"\n";
	else{
		sort(comp,comp+c);
		sum=(c-1)*comp[0];
		for(i=1;i<c;i++){
			//cout<<comp[i]<<" ";
			sum+=comp[i];
		}
		cout<<sum<<"\n";
	}

	#ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
    	
	return 0;
}
