#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p; //first ³Ìµu¶ZÂ÷ second ³»ÂI½s¸¹ 
struct edge{
	int cost;
	int to;
};
typedef edge edge;
vector<edge> G[20000+5];
int dis[20000+5];

void solve(int s){
	priority_queue<p,vector<p>,greater<p>> pq;
	for(int i=0;i<20000+5;i++){
		dis[i]=99999;
	}
	while(!pq.empty()) pq.pop();
	dis[s] = 0;
	pq.push(p(0,s));
	while(!pq.empty()){
		p P = pq.top();
		pq.pop();
		int v = P.second;
		for(int i=0 ; i < G[v].size() ; i++){
			edge e = G[v][i];
			if(dis[e.to] > dis[v] + e.cost){
				dis[e.to] = dis[v] + e.cost;
				pq.push(p(dis[e.to],e.to));
			}
		}
	}
}

int main(){
	int ncase;
	while(cin>>ncase){
		while(ncase--){
			int n,r,s,b;
			cin.tie(0);
			cin.sync_with_stdio(0);
			cin>>n>>r>>s>>b;
			while(r--){
				int a,c,delay;
				edge tmp1,tmp2;
				cin>>a>>c>>delay;
				tmp1.cost = delay,tmp2.cost=delay;
				tmp1.to = a,tmp2.to = c;
				G[c].push_back(tmp1);
				G[a].push_back(tmp2);
			}
			solve(s);
			if(dis[b]==99999){
				cout<<"YOU DIED\n";
			}else{
				cout<<dis[b]<<endl;
			}
			for(int i=0;i<20000+5;i++){
				G[i].clear();
			}
		}
	}
	return 0;
} 
