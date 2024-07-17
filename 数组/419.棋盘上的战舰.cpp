#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        // mxn
        int m = board.size();
        int n = board[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X')
                    if ( j-1 == -1  || j - 1 >= 0 && board[i][j - 1] == '.')
                        if ( i-1 ==-1 || i - 1 >= 0 && board[i - 1][j] == '.') {
                            count++;
                        }
            }
        }
        return count;
    }
};
