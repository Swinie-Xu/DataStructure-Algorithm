class Solution {
public:
    double Power(double base, int exponent) {
        // 自己写的代码，忘了考虑负数幂的情况
        // 就是用的最原始的数学定义，多个数累乘
        double ret = 1.0;
        if(exponent>0)
        {
            for (int i=1;i<=exponent;++i ) ret*=base;
            return ret;
        }
        else 
        {
            for(int i=1;i<=-exponent;++i ) ret*=base;
            return 1/ret;
        }
    }
};
