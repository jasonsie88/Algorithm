#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& v,int len){
	map<int,int> fre;
	int max=-1,index=0,diff=0,ans;
	for(int i=0;i<v.size();i++){
		fre[v[i]]++;
		if(fre[v[i]]==1){
			diff++;
		}
		if(fre[v[i]]>max){
			max=fre[v[i]];
		}
	}
	if(diff>=max){
		diff--;  //當diff<max時 例: 5555 3333  diff:2 max:4  len:4  要回傳 diff 一定不回傳 max 或 len  不會有因 diff 和 max 重複計算產生的衝突  
	}
	if(len<=max&&len<=diff){ 
		return len;
	}else if(diff<=max&&diff<=len){
		return diff;
	}else {
		return max;
	}
}
int main(){
	int ncase,len,ans;
	vector<int> v;
	cin>>ncase;
		for(int i=0;i<ncase;i++){
			v.clear();
			cin>>len;
			for(int j=0;j<len;j++){
				int tmp;
				cin>>tmp;
				v.push_back(tmp);
			}
			len/=2;
			ans=solve(v,len);
			cout<<ans<<endl;			
		}
	return 0;		
}
	

