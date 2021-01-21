#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p; //first 最短距離 second 頂點編號
struct edge{
	int open;
	int close;
	int cost;
	int to;
}; 
typedef edge edge;
vector<edge> G[10000+5]; //2D vector
 int dis[10000+5];

void solve(int s){
	priority_queue<p,vector<p>,greater<p>> pq;
	for(int i=0;i<10000+5;i++){
		dis[i] = 999999999;
	}
	while(!pq.empty()) pq.pop();
	dis[s] = 0;
	pq.push(p(dis[s],s));
	while(!pq.empty()){
		p P = pq.top();
		pq.pop();
		int v = P.second;
		for(int i=0;i<G[v].size();i++){
			edge e = G[v][i];
			int judge = dis[v]%(e.open+e.close); //***** 取週期餘數    週期 = e.open + e.close *****//
			if(judge + e.cost <= e.open && dis[e.to] > dis[v] + e.cost && e.cost <= e.open){  ///要在open時間內走完 
				dis[e.to] = dis[v] + e.cost;
				pq.push(p(dis[e.to],e.to));
			}else if(judge + e.cost > e.open && dis[e.to] > dis[v] + e.open + e.close + e.cost - judge && e.cost <= e.open){
				dis[e.to] = dis[v] + e.open + e.close + e.cost - judge; //judge 相當 latency    太多 就要等下一次開門 
				pq.push(p(dis[e.to],e.to));
			}
		}
	}
}

int main(){
	int ncase;
	while(cin>>ncase){
		while(ncase--){
			for(int i=0;i<10000+5;i++){
				G[i].clear();
			}
			cin.tie(0);
			cin.sync_with_stdio(0);
			int N,M,S,T;
			cin>>N>>M>>S>>T;
			while(M--){
				int open,close,cost,to,from;
				edge tmp1;
				cin>>from>>to>>open>>close>>cost;
				//tmp1.open = open;
				//tmp1.close = close;
				//tmp1.cost = cost;
				//tmp1.to = to;
				G[from].push_back(edge{open,close,cost,to});
			}
			solve(S);
			cout<<dis[T]<<"\n";
		}
	}
	return 0;
}
