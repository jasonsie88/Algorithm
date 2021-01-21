#include<bits/stdc++.h>
using namespace std;
map<string,string> old_dic;
map<string,string> new_dic;
vector<string> add;
vector<string> sub;
vector<string> star;
void split(string str,bool flag){
	for(int i=0;i<str.length();){
		string s1,s2;	
		while(!isalpha(str[i]) && i<str.length()){
			i++;  //¶¶§Ç¤£¯à§ï
				  //, { 
		}
		while(isalpha(str[i])&&i<str.length()){
			s1+=str[i];
			i++;
		}		
		while(!isdigit(str[i]) && i<str.length()){
			i++;
			//:
		}
		while(isdigit(str[i])&&i<str.length()){
			s2+=str[i];
			i++;
		}		
		if(flag){
			old_dic[s1]=s2;
		}else{
			new_dic[s1]=s2;
		}		
	}
}
void compare(){
	for(auto it=old_dic.begin();it!=old_dic.end();it++){
		if(!new_dic.count(it->first)){
			sub.push_back(it->first);
		}else{
			if(it->second!=new_dic[it->first]){
				star.push_back(it->first);
			}	
		}
	}
	for(auto it=new_dic.begin();it!=new_dic.end();it++){
		if(!old_dic.count(it->first)){
			add.push_back(it->first);			
		}
	}	
}
void print(vector<string> v){
	for(int i=0;i<v.size();i++){
		if(i==0){
			cout<<v[i];
		}else{
			cout<<","<<v[i];
		}
	}
	cout<<endl;
}
int main(){
	int ncase;
	string input1,input2;	
	while(cin>>ncase){
		for(int i=0;i<ncase;i++){
			add.clear();
			sub.clear();
			star.clear();
			old_dic.clear();
			new_dic.clear();
			cin>>input1>>input2;
			split(input1,1),split(input2,0);
			compare();
			if(add.empty() && sub.empty() && star.empty()){
				cout<<"No changes\n";
			}
			if(!add.empty()){
				cout<<"+";
				print(add);	
			}
			if(!sub.empty()){
				cout<<"-";
				print(sub);
			}
			if(!star.empty()){
				cout<<"*";
				print(star);
			}
			cout<<endl;
		}
	}
	return 0;
}
