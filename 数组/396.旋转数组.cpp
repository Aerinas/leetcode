//超时代码o n^2
#include <vector>
#include <iostream>
using namespace std; 
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int f=0;
         for(int j =1;j<n;j++){
               f+= nums[j]*j;
            }
             for(int i = 0;i<n;i++)
        {
            rotate(nums.begin(),nums.end()-1,nums.end());
             int f1 =0;
            for(int j =1;j<n;j++){
               f1+= nums[j]*j;
            }
            if(f<f1){
                f = f1;
            }
        }
    return f;
    }
};

#include <vector>
#include <iostream>
#include <numeric> // for std::accumulate
#include <climits> // for INT_MIN
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int f = 0;

        // 初始计算 F(0)
        for (int i = 0; i < n; ++i) {
            f += i * nums[i];
        }

        int maxF = f;

        // 使用公式 F(k) = F(k-1) + sum - n * nums[n-k] 计算其他旋转函数值
        for (int k = 1; k < n; ++k) {
            f = f + sum - n * nums[n - k];
            maxF = max(maxF, f);
        }

        return maxF;
    }
};
//修正案
int main() {
    Solution sol;
    vector<int> nums = {4, 3, 2, 6};
    cout << sol.maxRotateFunction(nums) << endl;
    return 0;
}
