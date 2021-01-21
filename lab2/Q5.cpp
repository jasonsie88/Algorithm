#include<bits/stdc++.h>
using namespace std;
map<vector<int>,bool> flag;
map<vector<int>,int> order;
vector<pair<pair<vector<int>,vector<int>>, int>> dis;
vector<vector<int>> points;

 int distance(int x1,int y1,int x2,int y2){
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

bool cmp(const pair<pair<vector<int>,vector<int>>, int> a, const pair<pair<vector<int>,vector<int>>, int> b){
	pair<vector<int>,vector<int>> p1 = a.first;
	pair<vector<int>,vector<int>> p2 = b.first;
	vector<int> v1 = p1.first;
	vector<int> v2 = p1.second;
	int d1,d2;
	d1 = min(distance(20000,20000,v1[0],v1[1]),distance(20000,20000,v2[0],v2[1]));
	vector<int> v3 = p2.first;
	vector<int> v4 = p2.second;
	d1 = min(distance(20000,20000,v3[0],v3[1]),distance(20000,20000,v4[0],v4[1]));
	if(a.second==b.second){
		return d1 < d2;
	}else{
		return a.second < b.second;
	}
}


void solve(int& count){
	for(auto iter=dis.begin();iter!=dis.end();iter++){
		pair<vector<int>,vector<int>> p4 = iter->first ;
		vector<int> m1 = p4.first;
		vector<int> m2 = p4.second;
		if(flag[m1] !=0 && flag[m2] !=0){
			if(distance(m1[0],m1[1],20000,20000) < distance(m2[0],m2[1],20000,20000)){
				flag[m1]=0;
				count++;
			}else if(distance(m1[0],m1[1],20000,20000) > distance(m2[0],m2[1],20000,20000)){
				flag[m2]=0;
				count++;
			}else{
				if(order[m1] < order[m2]){
					flag[m1]=0;
					count++;
				}else{
					flag[m2]=0;
					count++;
				}
			}
		}
	}
}


int main(){
	int ncase,x,y,count,r;
	vector<int> tmp;
	while(cin>>ncase){
		count=0;
		r=0;
		dis.clear();
		order.clear();
		flag.clear();
		points.clear();
		while(ncase--){
			cin>>x>>y;
			tmp.push_back(x);
			tmp.push_back(y);
			order[tmp]=r++;
			flag[tmp]=1;
			points.push_back(tmp);
			tmp.clear();
		}
		
		for(auto iter1=points.begin();iter1!= --points.end();iter1++){
			for(auto iter2 = ++points.begin(); iter2!=points.end() ;iter2++){
				vector<int> p1; 
				p1 = *iter1;
				vector<int> p2; 
				p2 = *iter2;
				if(distance(p1[0],p1[1],p2[0],p2[1]) < 40000 && distance(p1[0],p1[1],p2[0],p2[1]) != 0){
					pair<vector<int>,vector<int>> p3;
					pair<pair<vector<int>,vector<int>>,int> p4;
					p3 = make_pair(p1,p2);
					p4=make_pair(p3,distance(p1[0],p1[1],p2[0],p2[1]));
					dis.push_back(p4); 
				}
			}
		}
		sort(dis.begin(),dis.end(),cmp);
		solve(count);
		cout<<"Number of removed 7-11 stores: "<<count<<endl;
	}
	return 0;
} 
