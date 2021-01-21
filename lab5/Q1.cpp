#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
struct show{
	int start;
	int end;
};
typedef show show;
vector<show> vec;
bool cmp(show a,show b){
	if(a.end==b.end){
		return a.start < b.start;
	}else{
		return a.end < b.end;
	}
}
void solve(int& ans){
	sort(vec.begin(),vec.end(),cmp);
	int i=0;
	for(int j=1;j<vec.size();j++){
		if(vec[j].start >=vec[i].end){
			ans++;
			i=j;
		}
	}
}

int main(){
	int ncase,len,ans;
  	cin.tie(0);
  	cin.sync_with_stdio(0);
	while(cin>>ncase){
		while(ncase--){
			cin>>len;
			vec.clear();
			ans = 1;
			for(int i=0;i<len;i++){
				show tmp;
				int s,e;
				cin>>s>>e;
				tmp.start = s;
				tmp.end = e;
				vec.push_back(tmp);
			}
			solve(ans);
			cout<<ans<<endl;			
		}
	}
	return 0;
}
