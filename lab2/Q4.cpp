#include<bits/stdc++.h>
using namespace std;
int maze[70][70];
bool visit[70][70];
bool safe(int x,int y,int m,int n){
	if(x<0 || y<0 || x>=m || y>=n){
		return false;
	}
	return true;
}
void solve(int m,int n,int x,int y,int& count,int pre){
	if(x==m-1 && y==n-1 && maze[x][y]!=0){
		count++;
		return;
	}
	visit[x][y]=1;
	if(safe(x,y,m,n) && maze[x][y]!=0){
		if(maze[x][y]==1){
			if(pre==1){
				if(y+1<n && !visit[x][y+1]){
					solve(m,n,x,y+1,count,pre);
				}	
				if(y-1>=0 && !visit[x][y-1]){
					solve(m,n,x,y-1,count,pre);					
				}
			}else if(pre==0){
				if(x+1<m && !visit[x+1][y]){
					solve(m,n,x+1,y,count,pre);
				}
				if(x-1>=0 && !visit[x-1][y]){
					solve(m,n,x-1,y,count,pre);
				}
			}
		}
		if(maze[x][y]==2){
			if(pre==1){
				
				if(x+1<m && !visit[x+1][y]){
					solve(m,n,x+1,y,count,0);
				}
				if(x-1>=0 && !visit[x-1][y]){
					solve(m,n,x-1,y,count,0);
				}			
			}else if(pre==0){
				
				if(y+1<n && !visit[x][y+1]){
					solve(m,n,x,y+1,count,1);
				}	
				if(y-1>=0 && !visit[x][y-1]){
					solve(m,n,x,y-1,count,1);
				}				
			}			
		}		
	}	
	visit[x][y]=0;
}

int main(){
	int ncase;
	while(cin>>ncase){
		while(ncase--){
			memset(maze,0,sizeof(maze));
			memset(visit,0,sizeof(visit));
			int m,n,count1=0,count2=0;
			char tmp;
			cin>>m>>n;
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					cin>>tmp;
					if(tmp=='B'){
						maze[i][j]=0;
					}
					if(tmp== 'L' ){
						maze[i][j]=1;
					}
					if(tmp=='T'){
						maze[i][j]=2;
					}
				}
			}
			solve(m,n,0,0,count2,0);  // 0 ª½¨«  1 ¾î¨« 
			solve(m,n,0,0,count1,1); 
			 cout<<"Number of legal solutions: "<<count1+count2<<endl;			
		}
	}	
	return 0;
} 
