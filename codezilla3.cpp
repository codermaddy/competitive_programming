#include <bits/stdc++.h>

#define pb push_back
#define INF 999999999
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
	int N,cnt[5000];
	string S;
	string ans;
	cin>>N;
	cin>>S;
	memset(cnt,0,sizeof cnt);
	int sum = 0;
	for(int i=0;i<S.size();i++){
		if(S[i] == '1'){
			ans.append("a");
		}
		else if(S[i] == '2'){
			ans.append("bb");
			//ans.append('b');
		}
		else if(S[i] == '3'){
			ans.append("ab");
			//ans.append('b');
		}
		else if(S[i] == '4'){
			for(int j=0;j<ans.size();j++){
				if(ans[j] == 'a')
					ans[j] = 'b';
				else
					ans[j] = 'a';
			}
		}
	}
	cout<<ans<<"\n";
	//cout<<cnt<<"\n";
	return 0;
}