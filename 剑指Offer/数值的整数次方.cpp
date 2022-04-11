class Solution {
public:
    // 递归版本的快速幂
    double quick_power(double base,int exponent)
    {
        if(exponent==0) return 1.0;
        double ret = quick_power(base, exponent/2);
        if( exponent&1 )   // exponent&1 判断为奇数
        {
            return ret*ret*base;
        }else return ret*ret;
    }
    
    double Power(double base, int exponent) {
        if(exponent<0)
        {
            base = 1/base;
            exponent = -exponent;
        }
        return quick_power(base, exponent);
    }
};
