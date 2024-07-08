#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int j = -1;
        int l = nums.size();
        int rep, missing = 0;
        for (int n : nums) {
            if (j == n) {
                rep = n;
                nums.erase(remove(nums.begin(), nums.end(), j), nums.end());
                nums.push_back(rep);
                sort(nums.begin(), nums.end());
                break;
            } else {
                j = n;
            }
        }
        j = 1;
        for (int n :
             nums) { // 122 11 1233 or 1223 -> 123 2344 -> 234 missing 1 1 345
            if (j != n) {
                missing = n - 1;
                break;
            } else {
                j++;
            }
        }
        if (!missing) {
            missing = l;
        }
        return {rep, missing};
    }
};

//gptversion
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int rep = -1;
        int missing = -1;

        // Sort the nums array
        sort(nums.begin(), nums.end());

        // Find the duplicate number
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1]) {
                rep = nums[i];
                break;
            }
        }

        // Calculate the expected sum of the first n natural numbers
        int expected_sum = n * (n + 1) / 2;
        // Calculate the actual sum of the array excluding the duplicate
        int actual_sum = accumulate(nums.begin(), nums.end(), 0);

        // The missing number is the difference between the expected sum and the actual sum minus the duplicate
        missing = expected_sum - (actual_sum - rep);

        return {rep, missing};
    }
};

