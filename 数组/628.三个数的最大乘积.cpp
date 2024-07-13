#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int max1 = 1;
        int max2 = 1;
        int ans = 1;
        int l = nums.size();
        max1 = nums[l-1]*nums[l-2]*nums[l-3];
        max2 = nums[0]*nums[1]*nums[l-1];
        //  + + + = + ?
        //  - - + = + ?
        ans = max(max1,max2);
        return ans;
    }
};
