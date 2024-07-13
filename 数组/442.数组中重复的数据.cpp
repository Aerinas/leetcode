#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int l = nums.size();
        for(int i=0;i<l;i++ ){
            nums[(nums[i]-1)%l] += l;
        }
        for(int i=0;i<l;i++){
            if(nums[i]>(2*l)){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
