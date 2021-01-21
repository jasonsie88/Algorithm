#include<bits/stdc++.h>
#define INF 0X3f3f3f3f
using namespace std;
struct node{
	int from;
	int to;
	int w;
};
typedef node node;
node arr[100+5];
int dis[100+5];
int n,m;
bool solve(){
	memset(dis,0,sizeof(dis));
	for(int i=0;i<=n;i++){
		dis[i]=INF;
	}
	dis[0]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int x=arr[j].from,y=arr[j].to,z=arr[j].w;
			if(dis[y] > dis[x] + z){
				dis[y]=dis[x]+z;
			}
		}
	}
	for(int i=0 ;i<m;i++){
		int x=arr[i].from,y=arr[i].to,z=arr[i].w;
		if(dis[y]>dis[x]+z){
			return false;
		}
	}
	return true;
}
int main(){
  cin.tie(0);
  cin.sync_with_stdio(0);	
	int x,y,z;
	char tmp;
	while(cin>>n>>m){
		memset(arr,0,sizeof(arr));
		if(n==0){
			break;
		}
		for(int i=0;i<m;i++){
			cin>>x>>y>>tmp>>z;
			if(tmp=='>'){
				arr[i].from=x; //求序列和 考慮頭尾 所以要+1 
				arr[i].to=x+y+1;
				arr[i].w=-z-1;  //把 >  -->  <   --->   <= 
			}else{
				arr[i].from=x+y+1;
				arr[i].to=x;
				arr[i].w=z-1;
			}			
		}
		if(solve()){
			cout<<"All aboard the hype bus choo choo.\n";
		}else{
			cout<<"There is no bus in Gensokyo.\n";
		}		
	}	
	return 0;
}
