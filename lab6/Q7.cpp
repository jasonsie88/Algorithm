#include<bits/stdc++.h>
using namespace std;
int arr[100+5][100+5]={0};
int visit[100+5]={0};
int match[100+5]={0};
int solve(int x,int m){
	for(int i=0;i<m;i++){
		if(visit[i]==0 && arr[x][i]==1){  //要有配對  而且沒有visit過 
			visit[i]=1;
			if(solve(match[i],m)==1 || match[i]==-1){  //solve() 幫被拆掉的人找新配偶  阿找不到就是 false    
				match[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	int ncase,n,m,k,x,y,ans=0;
	cin>>ncase;
	while(ncase--){
			ans=0;
			scanf("%d%d%d",&n,&m,&k);
			memset(arr,0,sizeof(arr));
			memset(match,-1,sizeof(match));
			for(int i=0;i<k;i++){
				cin>>x>>y;
				arr[x][y]=1;
			}
			for(int i=0;i<n;i++){
				memset(visit,0,sizeof(visit));
				if(solve(i,m)==1){
					++ans;
				}
			}
			cout<<ans<<endl;		
	}
	return 0;
}
