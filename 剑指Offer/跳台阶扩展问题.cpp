class Solution {
public:
    int jumpFloorII(int number) {
        // 用的数学推导，发现就是2的(n-1)次方种方法
        // 我自己推导有这个关系，不过我用的pow函数，这个是想起来左右移运算符的东西了
        return 1 << number-1;   // 这里左移之后表示 1 * 2^(n-1)
    }
};
