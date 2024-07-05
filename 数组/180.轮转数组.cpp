
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp;
        int n = nums.size();
              k = k % n;
        int p1 = 0 , p2 = 0;
                //先复制后K位
        p1 = n-k;
        for(;p1<n;p1++)
        {
            temp.push_back(nums[p1]);            
        }
        p2 = n-1;
        for(int i = n-k-1;i>=0 ;i--,p2--)
        {
            nums[p2]=nums[i];
        }
        int i =0;
        for(int v : temp)
        {
            nums[i]=v;
            i++;
        }
        
    }
};
