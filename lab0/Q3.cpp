#include<bits/stdc++.h>
using namespace std;
int main(){
	int ncase;
	while(scanf("%d ",&ncase)!=EOF){
		for(int i=0;i<ncase;i++){
			string input;
			stack<char> stk;
			getline(cin,input);	
			bool flag=true;
			while(!stk.empty()){
				stk.pop();
			}
			for(int j=0;j<input.size();j++){
				if(input[j]=='('||input[j]=='['){
					stk.push(input[j]);
				}
				if(input[j]==']'){
					if((!stk.empty())&&stk.top()=='['){
						stk.pop();
					}else{
						flag=false;
						break;
					}
				}
				if(input[j]==')'){
					if((!stk.empty())&&stk.top()=='('){
						stk.pop();
					}else{
						flag=false;
						break;
					}
				}
			}
			if(!stk.empty()){
				flag=false;
			}
			if(flag){
				cout<<"Yes\n";
			}else{
				cout<<"No\n";
			}
		}
	}
	return 0;
}
