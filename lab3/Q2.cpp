#include<bits/stdc++.h>
using namespace std;
typedef struct people people;
int visit[100000];

struct people{
	int time;
	vector<int> friends;
};

int result=0;
people member[100000];

void solve(int start,int& count){
	visit[start]=1;
	vector<int> v;
	v = member[start].friends;
	count += member[start].time;
	if(v.empty()){
		if(result<count){
			result=count;
		}
		count-=member[start].time; //走到最後退一步 
		return;
	}
	while(!v.empty()){
		int next = v.back();
		v.pop_back();
		if(!visit[next]){
			solve(next,count);
		}
	} 
	count-=member[start].time; //做完步驟退後 
	visit[start]=0; //可加可不加 
}



int main(){
	int ncase;
	while(cin>>ncase){
		int start,len,count;
		for(int i=0;i<ncase;i++){
			cin>>len>>start;
			count=0;
			result = 0;
			memset(visit,0,sizeof(visit));
			memset(member,0,sizeof(member));
			for(int i=0;i<len;i++){
				int tmp1,tmp2;
				cin>>tmp1>>tmp2;
				member[i].time = tmp2;
				if(tmp1!=-1)
				member[tmp1].friends.push_back(i);
			}
			solve(start,count);		
			cout<<result<<endl;
			
		}
	}
	return 0;
} 
