#include<bits/stdc++.h>
using namespace std;
struct bird{
	int x;
	int y;
	int t;
	int r;
};
typedef bird bird;
vector<bird> v;
bool cmp(bird a,bird b){
	return a.t < b.t;
}
int dis(int x1,int x2,int y1,int y2){
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int solve(int len){
	int ans=0,score=0;
	sort(v.begin(),v.end(),cmp);
	int dp[1000+5]={0};  //該點可以得到的最大報酬 
	for(int i=0;i<len;i++){
		dp[i]=v[i].r;
	}
	for(int i=0;i<len;i++){
		score=0;
		for(int j=0;j<i;j++){
			if(dis(v[i].t,v[j].t,0,0)>=dis(v[i].x,v[j].x,v[i].y,v[j].y)){
				score=max(score,dp[j]);				
			}
		}
		dp[i]+=score;
		ans=max(ans,dp[i]);
	}
	return ans;
}
int main(){
	int ncase,len;
  	cin.tie(0);
  	cin.sync_with_stdio(0);	
	while(cin>>ncase){
		while(ncase--){
			v.clear();
			cin>>len;
			for(int i=0;i<len;i++){
				int tmp1,tmp2,tmp3,tmp4;
				cin>>tmp1>>tmp2>>tmp3>>tmp4;
				v.push_back(bird{tmp1,tmp2,tmp3,tmp4});
			}
			cout<<solve(len)<<endl;
		}
	}
	return 0;
} 
