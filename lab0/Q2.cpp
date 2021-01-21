#include<bits/stdc++.h>
using namespace std;
int main(){
	string input;
	while(cin>>input){
	list<char> ans;
	list<char>::iterator iter=ans.begin();
	//iter=ans.begin();
	for(int i=0;i<input.size();i++){
		if(input[i]=='['){
			iter=ans.begin();
		}else if(input[i]==']'){
			iter=ans.end();
		}else{
			ans.insert(iter,input[i]);
		}
	}
	for(iter=ans.begin();iter!=ans.end();iter++){
		cout<<*iter;
	}
	 cout<<endl;
}
	return 0;
}
