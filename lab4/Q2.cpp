#include<bits/stdc++.h>
using namespace std;
typedef struct node node;
#define INF 0x3f3f3f3f
struct node{
	int from;
	int to;
	int cost;
};
node edge[5000];
int dis[5000];
int s,w; //s: node w:edge
bool solve(int start){
	for(int i=0;i<5000;i++){
		dis[i] = INF;
	}	
	dis[start]=0;
	for(int k=0 ; k < s-1 ; k++){ //跑 s-1 個 node 除了source 
		for(int i= 0 ; i < w ;i++){ //跑所有edge 
			if(dis[edge[i].from] + edge[i].cost < dis[edge[i].to]){
				dis[edge[i].to] = dis[edge[i].from] + edge[i].cost;
			}
		}
	}
	bool flag = true;
	for(int i= 0 ; i < w ;i++){  //check negative loop
		if(dis[edge[i].from] + edge[i].cost < dis[edge[i].to]){
			flag = false;
			break;
		}
	}	
	return flag;
}

int main(){
	cin.tie(0);
  	cin.sync_with_stdio(0);
	int ncase;
	cin>>ncase;
	while(ncase--){
		srand(time(NULL));
		memset(edge,0,sizeof(edge));
		cin>>s>>w;
		for(int i=0; i<w ;i++){
			int a,b,t;
			cin>>a>>b>>t;
			edge[i].from = a;
			edge[i].to = b;
			edge[i].cost = t;
		}
		int x = rand()%(w-1); //use random number to find "good" start point
		if(solve(x)){
			cout<<"El Psy Kongroo";
		}else{
			cout<<"This is the choice of Steins;Gate";
		}
		cout<<endl;
	}	
	return 0;
}
