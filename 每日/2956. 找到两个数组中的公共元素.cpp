#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        //nums1
        int answer1=0;
        int answer2=0;
        for(const auto& n : nums1){
            for(const auto& m : nums2){
                if(n == m){
                answer1++;
                break;
                }
            }
        }
         for(const auto& n : nums2){
            for(const auto& m : nums1){
                if(n == m){
                answer2++;
                break;}
            }
        }
        vector<int> ans;
        ans.push_back(answer1);
        ans.push_back(answer2);
        return ans;
    }
};
