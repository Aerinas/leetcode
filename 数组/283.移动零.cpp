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
//GPT优化
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int p1 = 0;  // p1指向当前要放置非0元素的位置
        
        // 遍历数组，找到所有非零元素，依次放到前面
        for (int p2 = 0; p2 < n; ++p2) {
            if (nums[p2] != 0) {
                // 只有当p1和p2不同时才进行赋值操作，避免不必要的赋值
                if (p1 != p2) {
                    nums[p1] = nums[p2];
                }
                ++p1;
            }
        }
        
        // 将剩余的位置填充为0
        for (; p1 < n; ++p1) {
            nums[p1] = 0;
        }
    }
};
