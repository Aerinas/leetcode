#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                int count = 0;
                for (int p = 0; p < 3; p++) {
                    for (int q = 0; q < 3; q++) {
                        if (i - 1 + p >= 0 && i - 1 + p < m && j - 1 + q >= 0 &&
                            j - 1 + q < n) {
                            sum += img[i - 1 + p][j - 1 + q];
                            count++;
                        }
                    }
                   
                }
                //cout << "sum:"<<sum <<"count:"<<count;
                 ans[i][j] = floor(sum / count);
            }
        }
        return ans;
    }
};
