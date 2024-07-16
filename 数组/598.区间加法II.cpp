class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mina = m , minb = n;
        for (const auto& op : ops){
            mina = min(mina , op[0]);
            minb = min(minb , op[1]);
        }
        return mina * minb;
    }
};


//模拟(超出内存限制)
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        vector<vector<int>> ans(m,vector<int>(n));
        int op_num = ops.size();
        for(int i =0;i<op_num;i++){
            int a1=0,b1=0;
            a1 = ops[i][0];
            b1 = ops[i][1];
            for(int j =0; j<b1;j++){
                for(int k =0; k<a1;k++){
                        ans[j][k]++;
                }
            }
        }
        int answer =0;
        int m =0;
        for(auto n : ans){
            if(m<n[0]){
                m = n[0];
                answer = 0;
            }
            else
            answer++;
        
        }
        return answer;


    }
};
