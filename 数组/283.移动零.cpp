class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int count = 0; // 计算有多少0
        //p1指向当前非0数，p2遍历
        int p1 =0, p2 =0;
        for( ; p2<n;p2++)
        {
            if(nums[p2]!= 0){
                nums[p1]=nums[p2];
                p1++; 
            }
 
        }
        for(;p1<n;p1++)
        {
            nums[p1]=0;
        }


    }
};
