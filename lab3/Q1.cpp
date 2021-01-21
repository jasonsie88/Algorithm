#include<bits/stdc++.h>
using namespace std;
vector<int> cards;
bool cards_visit[10000+1];
bool flag=false;
void solve(int len,int ini){
		if(cards[ini]==0){
			flag=true;
			return;
		}
		if(ini<0 || ini>=len){
			return;
		}	
		cards_visit[ini]=1;
		if(ini-cards[ini]>=0 && ini-cards[ini]<len && !cards_visit[ini-cards[ini]]){
			solve(len,ini-cards[ini]);
		}		
		if(ini+cards_visit[ini]>=0 && ini+cards[ini]<len && !cards_visit[ini+cards[ini]]){
			solve(len,ini+cards[ini]);
		}
	
}
int main(){
	int ncase,ini,len;
	while(cin>>ncase){
		for(int i=0;i<ncase;i++){
			cards.clear();
			memset(cards_visit,0,sizeof(cards_visit));
			cin>>len>>ini;
			for(int j=0;j<len;j++){
				int tmp;
				cin>>tmp;
				cards.push_back(tmp);
			}
			solve(len,ini);
			if(flag){
				cout<<"We will watch your career with great interest."<<endl;
			}else{
				cout<<"My disappointment is immeasurable, and my day is ruined."<<endl;	
			}
			flag=false;
		}
	}
	return 0;
} 
