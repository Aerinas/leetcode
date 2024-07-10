#include <vector>
using namespace std;
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int l = nums.size();
        if(l==1)
        return 1;
        int max=-1;
        int ha[50000]={0};
        vector<int> zhongshu;
        for(int n : nums){
            ha[n]++;
        }
        for(int i =0 ;i<50000;i++){
            if(max<= ha[i]){
                max = ha[i];
            }
        }
        for(int i =0 ;i<50000;i++){
            if(max == ha[i]){
                zhongshu.push_back(i);
            }
        }
        int ans=50000;
        int first = 0; int last =0;
        for(int n : zhongshu){
                int flag=0;
            for(int j = 0 ; j<l;j++){
                if( n == nums[j] && !flag){
                    first = j;
                    flag = 1;
                    last = j;
                }
                else if (n == nums[j] ) {
                    last = j;
                }               
            }
          //ans = min(ans,last-first+1)
            if(ans >= (last-first+1))
                ans = last-first+1;
        }
      return ans;
    }
};

//
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int l = nums.size(); // 获取数组长度
        if(l == 1) return 1; // 如果数组长度为1，直接返回1

        unordered_map<int, int> count; // 用于记录每个元素的出现次数
        unordered_map<int, pair<int, int>> positions; // 用于记录每个元素的第一次和最后一次出现的位置，pair<int, int> 分别表示第一次和最后一次出现的索引
        int max_count = 0; // 用于存储元素的最大出现次数

        for(int i = 0; i < l; i++) {
            int n = nums[i]; // 获取当前元素
            count[n]++; // 记录当前元素出现次数
            max_count = max(max_count, count[n]); // 更新最大出现次数
            if(positions.find(n) == positions.end()) {
                positions[n] = {i, i}; // 如果是第一次出现，记录其第一次和最后一次出现的位置
            } else {
                positions[n].second = i; // 更新最后一次出现的位置
            }
        }

        int ans = l; // 初始化结果为数组长度
        for(auto& p : count) { // 遍历出现次数的哈希表
            if(p.second == max_count) { // 如果当前元素的出现次数等于最大出现次数
                int length = positions[p.first].second - positions[p.first].first + 1; // 计算该元素形成的子数组长度
                ans = min(ans, length); // 更新最短子数组长度
            }
        }

        return ans; // 返回最短子数组长度
    }
};

