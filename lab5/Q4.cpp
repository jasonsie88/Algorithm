#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;


bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first-a.second < b.first-b.second;   //first:X //second:Y
}

void solve(int len){
	int ans=0;
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<len;i++){
		if(i<len/2){
			ans+=v[i].first;
		}else{
			ans+=v[i].second;
		}
	}
	cout<<ans<<endl;		
}

int main(){
	int ncase,len;
	cin>>ncase;
		while(ncase--){
			cin>>len;
			v.clear();
			for(int i=0;i<len;i++){
				int tmp1,tmp2;
				cin>>tmp1>>tmp2;
				v.push_back(make_pair(tmp1,tmp2));	
			}
			solve(len);			
		}
	
	return 0;
}
