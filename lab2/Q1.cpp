#include <bits/stdc++.h>
using namespace std;
    bool cmp(vector<int>& v1,vector<int>& v2){
	return v1[1]*v1[1]+v1[0]*v1[0] < v2[1]*v2[1]+v2[0]*v2[0];
}	
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ans;
        sort(points.begin(),points.end(),cmp);
        for(int i=0;i<K;i++){
        	ans.push_back(points[i]);
		}
        return ans;
    }
};

bool sortFunc(const vector<int>& v1, const vector<int>& v2 ){
    if(v1[0]==v2[0]){
        return v1[1] > v2[1];
    }
    else{
        return v1[0] > v2[0]; 
    }
} 


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y, k;
    vector<int> tmp;
    vector<vector<int>> points;
    vector<vector<int>> ans;
    cin >> n >> k;
    while(n--){
        cin >> x >> y;
        tmp.push_back(x);
        tmp.push_back(y);
        points.push_back(tmp); 
        tmp.clear();
    }

    Solution sol;
    ans = sol.kClosest(points,k);
    sort(ans.begin(), ans.end(),sortFunc); 
    for(auto it = ans.begin();it!=ans.end();it++){
        for (auto it2 = it->begin(); it2 != it->end(); it2++) {
            cout << *it2 << " ";
        }
        cout << endl;
    }
    return 0;
}


