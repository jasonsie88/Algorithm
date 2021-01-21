#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int x[750+5];
int y[750+5];
int d[750+5];
int M[750+5][750+5];
int parent[750+5];
bool visit[750+5];
typedef pair<int,int> p; 
vector<p> ans;
void init(){
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	memset(d,0,sizeof(d));
	memset(parent,0,sizeof(parent));
	memset(M,0,sizeof(M));
	memset(visit,0,sizeof(visit));
	ans.clear();
}
int dist(int x1,int x2,int y1,int y2){
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

// mst prime algorithm
void solve(int &num,int n){
	for(int i=1;i<=n;i++){
		parent[i]=-1;
		d[i]=INF;
	}
	int mi,v;
	d[1]=0;
	while(1){
		mi=INF;
		v=-1;
		for(int i=1;i<=n;i++){
			if(!visit[i] && mi>d[i]){
				mi=d[i];  //尋找最近的點 
				v=i;
			}
		}
		if(v==-1){
			break;
		}
		visit[v]=true;
		for(int i=1;i<=n;i++){
			if(!visit[i] && d[i]>M[v][i]){
				d[i]=M[v][i]; //relaxation 
				parent[i]=v;
			}
		}
		//cout<<"debug: "<<mi<<endl;
		//mi 可能為0 
		if(mi){
			ans.push_back(p(v,parent[v]));
			num++;			
		}
	}
}
int main(){
	int ncase,n,m,num;
	cin.tie(0);
	cin.sync_with_stdio(0);
	while(cin>>ncase){
		while(ncase--){
			init();
			num=0;
			cin>>n;
			for(int i=1;i<=n;i++){
				cin>>x[i]>>y[i];
			}	
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int tmp=dist(x[i],x[j],y[i],y[j]);
					M[i][j]=tmp;
					M[j][i]=tmp;
				}
			}
			cin>>m;
			for(int i=0;i<m;i++){
				int tmp1,tmp2;
				cin>>tmp1>>tmp2;
				M[tmp1][tmp2]=0;
				M[tmp2][tmp1]=0;
			}
			solve(num,n);
			cout<<num<<endl;
			if(num){
				for(int i=0;i<num;i++){
					cout<<ans[i].second<<" "<<ans[i].first<<endl; 
				}
			}					
		}
	}
	return 0;
} 
