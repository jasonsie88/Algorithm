#include<bits/stdc++.h>
using namespace std;

int main(){
	int ncase;
	while(cin>>ncase){
		if(ncase==0){
			break;
		}
		int a1[ncase+5],a2[ncase+5];		
		for(int i=0;i<ncase;i++){
				cin>>a1[i]>>a2[i];
		}		
		bool flag=true;
		if(ncase%2){
			cout<<"NO\n";
		}else{

			sort(a1,a1+ncase);
			sort(a2,a2+ncase);
			for(int i=0;i<ncase;i++){
				if(a1[i]!=a2[i]){
					flag=false;
					break;
				}
			}
			if(flag){
				cout<<"YES\n";
			}else{
				cout<<"NO\n";
			}
		}
	}
	return 0;		
} 


