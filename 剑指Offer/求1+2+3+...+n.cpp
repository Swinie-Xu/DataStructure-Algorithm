class Solution {
public:
    int Sum_Solution(int n) {
        // if不能用，改成了 && 与来完成判断
        n>1 && (n+=Sum_Solution(n-1));
        return n;
    }
};
