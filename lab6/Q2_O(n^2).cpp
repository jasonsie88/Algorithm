#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int solve(int len){
	int LIS[1000+5]={0},LDS[1000+5]={0},total=0;
	for(int i=0;i<len;++i){
		LIS[i]=1;
		for(int j=0;j<i;++j){
			if(v[j]<v[i]){
				LIS[i]=max(LIS[i],LIS[j]+1);
			}
		}
	}
	for(int i=len-1;i>=0;--i){
		LDS[i]=1;
		for(int j=len-1;j>i;--j){
			if(v[j]<v[i]){
				LDS[i]=max(LDS[i],LDS[j]+1);
			}
		}
	}
	for(int i=0;i<len;++i){
		if(LDS[i]<2 || LIS[i]<2){
			continue;
		}
		total=max(total,LDS[i]+LIS[i]-1);
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
