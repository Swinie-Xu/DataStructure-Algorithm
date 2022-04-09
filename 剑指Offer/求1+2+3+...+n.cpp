class Solution {
public:
    int Sum_Solution(int n) {
        // 我自己写的递归代码
        if (n==1) return 1;
        return n+Sum_Solution(n-1);
    }
};
