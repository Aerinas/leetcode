#include <vector>
    #include<algorithm>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      int l = nums.size();
      for(int i=0;i<l;i++){
        if(nums[i]<=0)
        nums[i] = l+1;
      }
      for(int i=0;i<l;++i){
        int num = abs(nums[i]);
        if(num<=l){
                nums[num-1] = -abs(nums[num-1]);
            }
      }
      for (int i = 0; i < l; ++i)
      {
        if( nums[i]>0 ){
            return i+1;
        }
      }
      return l+1;
    }
};
