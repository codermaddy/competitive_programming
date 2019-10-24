#include <bits/stdc++.h>

#define INF 999999999
#define MOD 1000000007
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> adj[10];
int color[10];
int full[10];
int vis[10][10];

int main(){
	int m, n, a, b, ans = 0, tmp;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	if(n<=6){
		cout<<m<<"\n";
	}
	else{
		for(int k=1;k<=7;k++){
			int cnt = 1;
			for(int i=1;i<=7;i++){
				if(i!=k){
					color[i] = cnt++;
				}
			}
			for(int c=1;c<=6;c++){
				color[k] = c;
				int tmp = 0;
				memset(vis, 0, sizeof vis);
				for(int u=1;u<=n;u++){
					for(int i=0;i<adj[u].size();i++){
						int v = adj[u][i];
						if(vis[color[u]][color[v]] == 0 || vis[color[v]][color[u]] == 0){
							vis[color[u]][color[v]] = 1;
							vis[color[v]][color[u]] = 1;
							tmp++;
						}
					}
				}
				//cout<<tmp<<"\n";
				ans = max(ans, tmp);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}