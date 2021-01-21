#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int>& v1,vector<int>& v2){
	map<int,int> fre;
	vector<int> res;
	for(int i=0;i<v1.size();i++){
		fre[v1[i]]++;
	}		
	for(int i=0;i<v2.size();i++){
		if(fre[v2[i]]>0){
			for(int j=0;j<fre[v2[i]];j++){
				res.push_back(v2[i]);
			}
			fre[v2[i]]=-1;
		}
	}
	for(auto iter=fre.begin();iter!=fre.end();iter++){
		if(iter->second!=-1){
			for(int i=0;i<iter->second;i++){
				res.push_back(iter->first);
			}
		}
	}
	return res;
}
int main(){
	int ncase,len1,len2;
	vector<int> v1,v2;
	while(cin>>ncase){
		while(ncase--){
			v1.clear(),v2.clear();
			cin>>len1>>len2;
			for(int i=0;i<len1;i++){
				int tmp;
				cin>>tmp;
				v1.push_back(tmp);
			}
			for(int i=0;i<len2;i++){
				int tmp;
				cin>>tmp;
				v2.push_back(tmp);
			}
			vector<int> ans=solve(v1,v2);
			for(int i=0;i<ans.size();i++){
				cout<<ans[i]<<" ";
			}
			cout<<endl;			
		}
	}
	return 0;
}
