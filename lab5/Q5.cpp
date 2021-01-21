#include<bits/stdc++.h>
using namespace std;
int arr[7];
void solve(){
	int total=arr[6];
	total+=arr[5];
	arr[1]-=11*arr[5];
	total+=arr[4];
	arr[2]-=5*arr[4];
	total+=(arr[3]/4);
	if(arr[3]%4==1){  //9   //¬D¤¤¶¡ 
		arr[2]-=5; //6  4   3  2   1 
		arr[1]-=7; //3  11  6  10  23 
		total++;
	}else if(arr[3]%4==2){  //18
		arr[2]-=3; // 4  2   1 
		arr[1]-=6; // 2  10  14 
		total++;
	}else if(arr[3]%4==3){ //27
		arr[2]-=1; // 2 
		arr[1]-=5; // 1
		total++;
	}
	if(arr[2]<0){
		arr[1]-=(arr[2]*(-1))*4;
		arr[2]=0;
	}
	if(arr[1]<0){
		arr[1]=0;
	}
	total+=(arr[1]+arr[2]*4)/36;
	if((arr[1]+4*arr[2])%36){
		total++;
	}
	cout<<total<<endl;
}
int main(){
	int ncase,len;
  	cin.tie(0);
  	cin.sync_with_stdio(0);	
	while(1){
		memset(arr,0,sizeof(arr));
		cin>>arr[1]>>arr[2]>>arr[3]>>arr[4]>>arr[5]>>arr[6];
		if(arr[1]==0 && arr[2]==0 && arr[3]==0 && arr[4]==0 && arr[5]==0 && arr[6]==0){
			break;
		}
		solve();
	}
	return 0;
} 
