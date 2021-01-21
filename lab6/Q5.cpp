#include<bits/stdc++.h>
using namespace std;


int solve(int n,int k){  // n 雞蛋  k 樓層 
	int dp[n+1]={0};
	int ans=0;
	for(ans=0; dp[n] < k ; ++ans){
		for(int i=n ; i>0 ;i--){
			dp[i]+=dp[i-1]+1;  //有破 dp[i-1]+1 (雞蛋少一顆，測試次數少一次) 沒破 dp[i] (雞蛋沒少，測試次數少一次)  用前面的結果 更新 現在的結果  
		}
	}
	return ans;
}

int main(){
	int n,k;
	while(cin>>n>>k){
		if(n==0 && k==0){
			break;
		}
		cout<<solve(n,k)<<endl;
	}	
	return 0;
}
