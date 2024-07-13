#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int sum = 0;
        for (int i = 0; i < timeSeries.size(); i++) {
            int n = timeSeries[i];

            if (i == (timeSeries.size() - 1)) {
                sum += duration;
                break;
            }
            if (n + duration > timeSeries[i + 1])
                sum += timeSeries[i + 1] - n;
            else
                sum += duration;
        }
        return sum;
    }
};
