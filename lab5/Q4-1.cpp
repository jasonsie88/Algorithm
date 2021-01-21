#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
bool cmp(pair<int,int> a,pair<int,int> b){
	return (a.second-a.first) > (b.second-b.first) ;
}


void solve(int len){
	int ans=0;
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<len/2;i++){
		ans+=v[i].first+v[len-i-1].second;
	}
	cout<<ans<<endl;		
}

int main(){
	int ncase,len;
	while(cin>>ncase){
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
	}

	
	return 0;
}
