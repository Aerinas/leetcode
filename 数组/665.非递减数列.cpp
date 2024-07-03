class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            int x = nums[i];
            int y = nums[i + 1];
            if (x > y) {
                // 次小
                int temp = 0;
                temp = y - 1;
                int judge = 0;
                // 判断这个数跟前一个数的关系
                // 如果这个数做最小更改后也可以满足条件则可以
                // 否则这个数列无论如何修改都不行
                if (i >= 1) {
                    // 前一个数改小
                    if (temp < nums[i - 1]) {
                        // 前一个数等于后面的数
                        if ((temp + 1) == nums[i - 1])
                            count++;
                        // 尝试后一个数改大
                        else if (i != n - 2 && (x + 1) > nums[i + 2])
                            return false;
                        else
                            count++;
                    } else
                        count++;

                } else if (x > y)
                    count++;
            }
        }
        if (count > 1) {
            return false;
        }
        return true;
    }
};
