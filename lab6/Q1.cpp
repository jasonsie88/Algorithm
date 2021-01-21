#include<bits/stdc++.h>
using namespace std;
//區間DP 
int solve(int n,string str){
	int dp[500+5][500+5]={0};
	for(int i=1;i<=n;i++){
		dp[i][i]=1;
	}
	for(int len=2;len<=n;len++){
		for(int right=len,left=1;right<=n;right++,left++){
		//	cout<<str[left]<<str[right]<<endl;
			if(str[left]==str[right]){
				dp[left][right]=dp[left+1][right-1]+1; //MATCH   dp[left+1][right-1] 上一個比對結果 
			}else{
				dp[left][right]=min(dp[left+1][right],dp[left][right-1])+1;
			}
			for(int k=left;k<=right;k++){
				dp[left][right]=min(dp[left][right],dp[left][k]+dp[k][right]-1);  //避免重複 3個以上 
			}
		//	cout<<left<<" "<<right<<endl;
		//	cout<<dp[left][right]<<endl;
		}
	}
//	for(int i=0;i<=n;i++){
//		for(int j=0;j<=n;j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	return dp[1][n];
}

int main(){
	int ncase,len;
	while(cin>>ncase){
		while(ncase--){
			string str;
			cin>>len;
			cin>>str;		
			str.insert(str.begin(),0);
			cout<<solve(len,str)<<endl;		
		}
	}
	return 0;
}
