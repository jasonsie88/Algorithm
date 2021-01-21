#include<bits/stdc++.h>
#define zero 0 
using namespace std;
int a[25+5][25+5]={0};
int row_exist[25][25]={0};
int col_exist[25][25]={0};
int block_exist[25][25]={0};
int block_num(int row,int col,int box_size){
	int i=row/box_size;
	int j=col/box_size;
	return i*box_size+j;
}

bool findzero(int size,int &row,int &col){
	for(row=0;row<size;++row){
		for(col=0;col<size;++col){
			if(a[row][col]==zero){
				return true;
		}
	}
}
	return false;
}

bool row_used(int row,int size,int ans){
	for(int col=0;col<size;++col){
		if(a[row][col]==ans){
			return true;
		}
	}
	return false;
}

bool col_used(int col,int size,int ans){
	for(int row=0;row<size;++row){
		if(a[row][col]==ans){
			return true;
		}
	}
	return false;
}

bool box_used(int box_row,int box_col,int box_size,int ans){
	for(int row=0;row<box_size;++row){
		for(int col=0;col<box_size;++col){
			if(a[row+box_row][col+box_col]==ans){
				return true;
			}
		}
	}
	return false;
}

bool check(int size,int box_size,int row,int col,int ans){
	return !row_used(row,size,ans) && !col_used(col,size,ans) && !box_used(row-row%box_size,col-col%box_size,box_size,ans) && a[row][col]==zero;
}

bool solve(int size,int box_size){
	int col,row;
	if(!findzero(size,row,col)){
		return true;
	}
	for(int ans=1;ans<=size;++ans){
		if(row_exist[row][ans] || col_exist[col][ans] || block_exist[block_num(row,col,box_size)][ans]){
			continue;
		}
		if( check(size,box_size,row,col,ans) ){
			a[row][col]=ans;
			row_exist[row][ans]=true;
			col_exist[col][ans]=true;
			block_exist[block_num(row,col,box_size)][ans]=true;			
			if(solve(size,box_size)){
				return true;
			}
			a[row][col]=zero;
			row_exist[row][ans]=false;
			col_exist[col][ans]=false;
			block_exist[block_num(row,col,box_size)][ans]=false;				
		}
	}
	return false;
}

void print(int size){
	for(int i=0;i<size;++i){
		for(int j=0;j<size;++j){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	vector<int> v;
	int tmp,size,box_size;
	while(scanf(" %d",&tmp)!=EOF){
		v.push_back(tmp);	
	}
	switch(v.size()){
		case 16:
			size=4;
			box_size=2;
			break;
		case 81:
			size=9;
			box_size=3;
			break;
		case 256:
			size=16;
			box_size=4;
			break;
		case 625:
			size=25;
			box_size=5;
			break;
	}
	for(int i=0;i<size;++i){
		for(int j=0;j<size;++j){
			row_exist[i][v[size*i+j]]=true;
			col_exist[j][v[size*i+j]]=true;
			block_exist[block_num(i,j,box_size)][v[size*i+j]]=true;
			a[i][j]=v[size*i+j];
		}
	}
	if(solve(size,box_size)){
		print(size);
	}else{
		cout<<"NO\n";
	}
	return 0;
}
