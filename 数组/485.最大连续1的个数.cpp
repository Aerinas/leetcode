class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = nums.size();
        int count =0;
        int ans=0;
        for(auto n :nums){
            if(n){
                count++;
                ans = max(ans,count);
            }
            else
            count=0;
        }
         return ans;
    }
   
};
