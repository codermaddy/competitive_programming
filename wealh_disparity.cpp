#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> adj[100002];
ll wealth[100002];
int N;

int bfs(int u){
	queue<int>Q;
	int v;
	bool vis[100002];
	ll max_w[100002];
	ll ans;
	memset(vis,0,sizeof vis);
	Q.push(u);
	max_w[u]=wealth[u];
	ans=0;
	vis[u]=1;
	while(!Q.empty()){
		v=Q.front();
		Q.pop();
		//cout<<v<<" "<<ans<<" "<<max_w<<" "<<wealth[v]<<endl;
		for(int i=0;i<adj[v].size();i++){
			if(!vis[adj[v][i]]){
				vis[adj[v][i]]=1;
				Q.push(adj[v][i]);
				ans=max(ans,max_w[v]-wealth[adj[v][i]]);
				max_w[adj[v][i]]=max(max_w[v],wealth[adj[v][i]]);
			}
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i,parent,hojo,j;
	cin>>N;
	for(i=1;i<=N;i++){
		cin>>wealth[i];
	}
	for(i=1;i<=N;i++){
		cin>>parent;
		if(parent!=-1){
			adj[parent].push_back(i);
		}
		else{
			hojo=i;
		}
	}
	/*for(i=1;i<=N;i++){
		cout<<i<<" ";
		for(j=0;j<adj[i].size();j++){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<bfs(hojo)<<endl;
	return 0;
}