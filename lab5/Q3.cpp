#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}

void solve(string a,string b){
	string ans;
	int l1=0,l2=0,r1=(a.size()+1)/2-1, /*最多只會用到一半  所邊界只有原來長度的一半*/r2=(a.size())/2-1,l=0,r=a.size()-1;
	ans.clear();
	ans.resize(a.size());
	sort(a.begin(),a.end());
	sort(b.begin(),b.end(),cmp);
	for(int i=0;i<a.size();i++){
		if(a[l1] >= b[l2]){ //l1,l2 跟 i 不同步 
						//從右邊開始填 
			if(i%2==0){
				ans[r--]=a[r1--];
			}else{
				ans[r--]=b[r2--];
			}
		}else{
			if(i%2==0){
				ans[l++]=a[l1++];
			}else{
				ans[l++]=b[l2++];
			}
		}			
	}		
	cout<<ans<<endl;
}
int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
	int ncase;
	while(cin>>ncase){
		while(ncase--){
			string str1,str2;
			cin>>str1>>str2;
			solve(str1,str2);
		}
	}
	return 0;
} 
