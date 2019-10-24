//Codechef Nov. 17
//ac

#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
	int T,ct_a,ct_b,index_a,index_b,i;
	stack<char> S;
	char x,tmp;
	string str;
	cin>>T;
	while(T--){
		cin>>str;
		//cout<<str<<" "<<str.size()<<endl;
		ct_a=0;
		ct_b=0;
		index_a=0;
		index_b=0;
		S.push('C');
		for(i=0;i<str.size();i++){
			x=S.top();
			tmp=str[i];
			//cout<<x<<" "<<tmp<<endl;
			if(tmp==x){
				if(x=='A'){
					ct_a+=i-index_a;
					index_a=i;
					index_b=0;
				}
				else{
					ct_b+=i-index_b;
					index_a=0;
					index_b=i;
				}
				S.pop();
				S.push(tmp);
			}
			else{
				if(tmp=='A'){
					ct_a++;
					index_a=i;
					index_b=0;
					S.pop();
					S.push(tmp);
				}
				else if(tmp=='B'){
					ct_b++;
					index_b=i;
					index_a=0;
					S.pop();
					S.push(tmp);
				}
			}
		}
		cout<<ct_a<<" "<<ct_b<<endl;
	}
	return 0;
}
