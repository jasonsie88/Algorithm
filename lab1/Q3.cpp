#include<bits/stdc++.h>
using namespace std;
int a[1000+5][1000+5];
void solve(int value,int row,int col){
	int i=row-1,j=0;
	bool check=false;
	while(i>=0 && j<col){
		if(value==a[i][j]){
			check=true;
			break;
		}else if(value<a[i][j]){
			i--;
		}else{
			j++;
		}
	}
	if(check){
		cout<<i<<" "<<j<<endl;
	}else{
		cout<<-1<<endl;
	}
}
int main(){
	int row,col,ncase;
	while(cin>>row>>col>>ncase){
		memset(a,0,sizeof(a));
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<ncase;i++){
			int input;
			cin>>input;
			solve(input,row,col);
		}
	}
	return 0;
} 
