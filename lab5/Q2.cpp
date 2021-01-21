#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;  //first dead second score
vector<p> vec;
bool cmp(p a,p b){
	return a.first < b.first;  //盡量把deadline 小的 排前   
}
long long int solve(int n){
	long long int ans=0;
	priority_queue<int,vector<int>,greater<int> > pq;
	sort(vec.begin(),vec.end(),cmp);
	for(int i=0;i<n;i++){
		if(vec[i].first > pq.size()){
			pq.push(vec[i].second);  //不能直接加 pq.top()  因為 pq.top() 不一定是 加進去的task 
			ans+=vec[i].second;
		}else if(vec[i].first==pq.size() && vec[i].second > pq.top()){
			ans-=pq.top();
			pq.pop();
			pq.push(vec[i].second);
			ans+=vec[i].second;
		}
	}
	return ans;
}
int main(){
	int ncase,len;
  	cin.tie(0);
  	cin.sync_with_stdio(0);	
	while(cin>>ncase){
		while(ncase--){
			vec.clear();
			cin>>len;
			for(int i=0;i<len;i++){
				int tmp1,tmp2;
				cin>>tmp1>>tmp2;
				vec.push_back(p(tmp1,tmp2));
			}
			cout<<solve(len)<<endl;
		}
	}
	return 0;
} 
