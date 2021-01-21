#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
struct node{
	int from;
	int to;
	int cost;
};
typedef node node;
node edge[5000];
int p[100+5];
bool cmp(node a,node b){
	return a.cost < b.cost;
}
 
void init(int n){
	memset(p,0,sizeof(p));
	for(int i=0;i<n;i++){
		p[i]=i;
	}
}

int find(int x){ 
	return p[x] == x ? x : p[x] = find(p[x]); 
}

void solve(int &ans,int n,int m){
	int count,x,y;
	for(int i=0;i<m;++i){
		init(n);
		count = 0;
		for(int j=i;j<m;++j){
			x = find(edge[j].from);
			y = find(edge[j].to);
			if(x != y){
				p[x] = y; //測試有沒有連通 
				count++;
				if(count==n-1){
					ans = min(ans,edge[j].cost-edge[i].cost);					
				}
			} 
		}
	}
}

int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
	int ncase,n,m,ans;
	while(cin>>ncase){
		while(ncase--){
			memset(edge,0,sizeof(edge));
			cin>>n>>m;
			ans=INF;
			for(int i=0;i<m;i++){
				int tmp1,tmp2,tmp3;
				cin>>tmp1>>tmp2>>tmp3;
				edge[i].from = tmp1;
				edge[i].to = tmp2;
				edge[i].cost = tmp3;
			}
			sort(edge,edge+m,cmp);
			solve(ans,n,m);
			ans=(ans==INF)?-1:ans;
			cout<<ans<<endl;
		}
	}
	return 0;
} 
