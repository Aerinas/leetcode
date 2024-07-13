#include <vector>
    #include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        //sort(nums.begin(),nums.end());
        int l = nums.size();
        int hash[100000]={0};
        for(int i =0 ;i<l;i++){
           hash[nums[i]] +=1;
        }
        for(int i =1; i<=l;i++){
            if(!hash[i])
            ans.push_back(i);
        }
        return ans;
    }
};
