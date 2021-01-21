#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
		int left=0,right=nums.size()-1,mid;
		while(left<=right){
			mid=left+(right-left)/2;
			if(nums[mid]==target){
				return mid;
			}
			if(nums[mid]>nums[right]){
				if(target<nums[mid] && target>=nums[left]){
					right=mid-1;
				}else{
					left=mid+1;
				}
			}else{
				if(nums[mid]<target && nums[right]>=target){
					left=mid+1;
				}else{
					right=mid-1;
				}
			}
		}
        return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int M, N;
    int tmp;
    vector<int> v;
    Solution sol;
    cin >> M >> N;

    while(M--){
        cin >> tmp;
        v.push_back(tmp);
    }
    while(N--){
        cin >> tmp;
        cout << sol.search(v,tmp) << endl;
    }

    return 0;
}
