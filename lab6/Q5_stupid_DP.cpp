#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

long long int solve(long long int n,long long int k){  // n Âû³J  k ¼Ó¼h 
	long long int arr[n+1][k+1]={0};
	long long int i,j,x,ans;
	for(i=1;i<=n;i++){
		arr[i][1]=1;
		arr[i][0]=0;
	}
	for(i=1;i<=k;i++){
		arr[1][i]=i;
	}
	for(i=2;i<=n;i++){
		for(j=2;j<=k;j++){
			arr[i][j]=INF;
			for(x=1;x<=j;x++){
				ans=1+max(arr[i-1][x-1],arr[i][j-x]);
				arr[i][j]=min(arr[i][j],ans);
			}
		}
	} 
	return arr[n][k];
}

int main(){
	  cin.tie(0);
  cin.sync_with_stdio(0);
	long long int n,k;
	while(cin>>n>>k){
		if(n==0 && k==0){
			break;
		}
		cout<<solve(n,k)<<endl;
	}	
	return 0;
}
