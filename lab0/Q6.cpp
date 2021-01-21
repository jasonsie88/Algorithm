#include<bits/stdc++.h>
using namespace std;
struct task{
	bool stop;
	int value;
};
int main(){
	int ncase;
	while(cin>>ncase){
		for(int i=0;i<ncase;i++){
			int len,m,ans=0;
			cin>>len>>m;
			queue<struct task> q;
			int a[len];
			for(int j=0;j<len;j++){
				task job;
				cin>>a[j];
				if(j==m){
					job.stop=true;
					job.value=a[j];
				}else{
					job.stop=false;
					job.value=a[j];
				}
				q.push(job);
			}
			sort(a,a+len);
		while(1){
			if(a[len-1]>q.front().value){
				task tmp=q.front();
				q.pop();
				q.push(tmp);
			}else{
				ans++;	
				if(q.front().stop){
					break;
				}			
				q.pop();
				len--;
			}		
		}
		cout<<ans<<endl;
		}
	}
	return 0;
} 
