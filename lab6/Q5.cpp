#include<bits/stdc++.h>
using namespace std;


int solve(int n,int k){  // n ���J  k �Ӽh 
	int dp[n+1]={0};
	int ans=0;
	for(ans=0; dp[n] < k ; ++ans){
		for(int i=n ; i>0 ;i--){
			dp[i]+=dp[i-1]+1;  //���} dp[i-1]+1 (���J�֤@���A���զ��Ƥ֤@��) �S�} dp[i] (���J�S�֡A���զ��Ƥ֤@��)  �Ϋe�������G ��s �{�b�����G  
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
