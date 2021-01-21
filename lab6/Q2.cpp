#include<bits/stdc++.h>
using namespace std;
// O(nlogn)
vector<int> v;
int solve(int len){
	int LIS[1000+5]={0},LDS[1000+5]={0},total=0;
	vector<int> v1;
	v1.clear();
	for(int i=0;i<len;++i){
		auto it=lower_bound(v1.begin(),v1.end(),v[i]);  //lower_bound vector中第一個比他大的數字 
		if(it==v1.end()){
			v1.push_back(v[i]);
		//	LIS[i]=v1.size(); //v1 LIS/LDS序列 
		}else{
			*it = v[i];  //替換掉 
		//	LIS[i]=it-v1.begin()+1; //更新長度
		//	LIS[i]=v1.size();
		}
		LIS[i]=v1.size();
	}
	v1.clear();
	for(int i=len-1;i>=0;--i){
		auto it=lower_bound(v1.begin(),v1.end(),v[i]);
		if(it==v1.end()){
			v1.push_back(v[i]);
		//	LDS[i]=v1.size();
		}else{
			*it = v[i];
		//	LDS[i]=it-v1.begin()+1;
		}
		LDS[i]=v1.size();
	}
	for(int i=0;i<len;++i){
		if(LDS[i]>=2 && LIS[i]>=2 ){
			total =max(total,LIS[i]+LDS[i]-1); 
		}
	}
	return len-total;
}

int main(){
	int ncase;
	while(cin>>ncase){
		while(ncase--){
			int len;
			v.clear();
			cin>>len;
			for(int i=0;i<len;i++){
				int tmp;
				cin>>tmp;
				v.push_back(tmp);
			}
			cout<<solve(len)<<endl;			
		}
	}
	return 0;
} 
