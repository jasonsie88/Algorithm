#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 10000

struct edge{
	int dir;
	int cost;
	int rev;
};

typedef edge edge;

vector<edge> G[MAX];
bool visited[MAX];
void add_edge(int from,int to,int cost){
	edge tmp1;
	tmp1.dir=to,tmp1.cost=cost,tmp1.rev=G[to].size();
	G[from].push_back(tmp1);
	edge tmp2;
	tmp2.dir=from,tmp2.cost=0,tmp2.rev=G[from].size()-1;
	G[to].push_back(tmp2);
}
int solve(int s,int t,int flow){
	if(s==t){
		return flow;
	}
	visited[s]=true;
	for(int i=0;i<G[s].size();i++){
	//	edge& e=G[s][i];
		if( !visited[G[s][i].dir] && G[s][i].cost > 0){
			int cap;
			cap=solve(G[s][i].dir,t,min(flow,G[s][i].cost));
			if(cap>0){
				G[s][i].cost-=cap;
				G[G[s][i].dir][G[s][i].rev].cost+=cap;
				return cap;
			}
		}
	}
	return 0;
}

int main(){
	int ncase;
	while(cin>>ncase){
		while(ncase--){
			int n,m,p,a;
			cin>>n>>m>>p>>a;
			vector<int> power;
			power.clear();
			map<int,int> power_cap;
			power_cap.clear();
			vector<int> client;
			client.clear();
			map<int,int> client_cap;
			client_cap.clear();
			for(int i=0;i<p;i++){
				int tmp;
				cin>>tmp;
				power.push_back(tmp);
			}
			for(int i=0;i<a;i++){
				int tmp1;
				cin>>tmp1;
				client.push_back(tmp1);
			}
			for(int i=0;i<m;i++){
				vector<int>:: iterator it1;
				vector<int>:: iterator it2;
				int from,to,cap;
				cin>>from>>to>>cap;
				it1=find(power.begin(),power.end(),from);
				it2=find(client.begin(),client.end(),to);				
				add_edge(from,to,cap);
				if(it1!=power.end()){
					power_cap[*it1]+=cap;
				}
				if(it2!=client.end()){
					client_cap[*it2]+=cap;	
				}				
			}
			for(auto iter=power_cap.begin();iter!=power_cap.end();iter++){
				if(iter->second!=0){
					add_edge(0,iter->first,iter->second);
				//	add_edge(0,iter->first,1);
					//SECOND 可以改成INF 
				}
			}
			for(auto iter=client_cap.begin();iter!=client_cap.end();iter++){
				if(iter->second!=0){
					add_edge(iter->first,n+1,iter->second);
					//add_edge(iter->first,n+1,1);
					//SECOND 可以改成INF 
				}
			}
			int ans=0;
			while(1){
				memset(visited,0,sizeof(visited));
				int flow=solve(0,n+1,INF);
				if(flow==0){
					break;
				}else{
					ans+=flow;
				}
			}
			cout<<ans<<endl;
			for(int i=0;i<10000;i++){
				G[i].clear();
			}
		}
	}
	return 0;
} 
