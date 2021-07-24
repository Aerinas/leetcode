//整数反转，思路很简单，提交的时候主要是遇到一个临界条件的检查。 正常一个非溢出的int 在翻转后 有可能会溢出 所以在反转进行到最后一位数的时候要检查 如果此时的数已经大于max/10
//或者小于min/10 下一次再*10的时候必溢出 可以直接跳出循环返回0

class Solution {
public:
    int reverse(int x) {
        
        int fflag=0;
        int temp=0;
        int num = x;
        while(num){
            
            if(temp > INT_MAX /10 || temp < INT_MIN /10) return 0;
            temp = temp * 10;
            temp += num % 10;
            int test  = num % 10;
            num = num / 10;
        
     
        }
  
        return temp;
    }
};
