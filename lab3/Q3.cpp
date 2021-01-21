#include<bits/stdc++.h>
using namespace std;
bool adj[10000+5][10000+5];
vector<int> ans;
bool cycle=false;
typedef struct room;
struct room{
	int index;
	int startTime;
	int finishTime;
	bool visit=false;
};
room rooms[10000+5];
int solve(int start,int R,int N,int& time){
	if(rooms[start].visit){
		cycle = true;
	}
	rooms[start].index=start;
	rooms[start].startTime=time;
	time++;
	rooms[start].visit=1;
	for(int i=0;i<R;i++){
		if(adj[start][i] ){
			time=solve(i,R,N,time);
			time++;
		}
	}
	rooms[start].finishTime=time;
	return time;
}
bool cmp(room a,room b){
	return a.finishTime>b.finishTime;
}
void print(int R){
	sort(rooms,rooms+R-1,cmp);
	for(int i=0;i<R;i++){
		cout<<rooms[i].index<<" "<<endl;
	}
	cout<<endl;
}
int main(){
	int ncase;
	while(cin>>ncase){
		for(int i=0;i<ncase;i++){
			ans.clear();
			memset(rooms,0,sizeof(rooms));
			memset(adj,0,sizeof(adj));
			cycle=false;
			int R,K,N,time=0;
			cin>>R>>K>>N;
			ans.assign(R,-1);
			for(int j=0;j<K;j++){
				int tmp1,tmp2;
				cin>>tmp1>>tmp2;
				adj[tmp1][tmp2]=1;
			}
			int tmp;
			for(int j=0;j<R;j++){
				if(!rooms[j].visit){
					tmp=solve(j,R,N,time);
				}
			}
			if(cycle){
				cout<<"Lion can not pass this chapter!\n";
			}else{
				print(R);
			}
		}
	}
	return 0;
}
