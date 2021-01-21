#include<bits/stdc++.h>
using namespace std;
char a[200000+5],b[200000+5];
bool cmp(char *a,char *b,int len){
	for(int i=0;i<len;i++){
		if(*(b+i) != *(a+i)){
			return false;
		}
	}
	return true;
}
bool solve(char *a,char *b,int len){
	if(cmp(a,b,len)){
		return true;
	}
	if(len%2==0){
		if((solve(a,b,len/2) && solve(a+len/2,b+len/2,len/2)) || (solve(a+len/2,b,len/2) && solve(a,b+len/2,len/2))){
			return true;
		}
	}
	return false;
}
int main(){
	int ncase;
	while(cin>>ncase){
		for(int i=0;i<ncase;i++){
			scanf("%s%s",&a,&b);	
			int len=(int)strlen(a);
			if(solve(a,b,len)){
				cout<<"Yes\n";
			}else{
				cout<<"No\n";
			}
		}
	}
	return 0;
}
