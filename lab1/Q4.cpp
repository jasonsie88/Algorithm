#include<bits/stdc++.h>
using namespace std;
bool cmp(string a,string b){
	return a+b<b+a;//¦r¨å§Ç 
}
int main(){
	int ncase,len;
	vector<string> ans;
	string output;
	while(cin>>ncase){
		for(int i=0;i<ncase;i++){
			ans.clear();
			output.clear();
			cin>>len;
			for(int j=0;j<len;j++){
				string tmp;
				cin>>tmp;
				ans.push_back(tmp); 
			}			
		sort(ans.begin(),ans.end(),cmp);
		for(int j=ans.size()-1;j>=0;j--){
			output+=ans[j];
		}
		cout<<output<<endl;
	}		
	}
	return 0;
} 
