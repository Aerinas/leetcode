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
