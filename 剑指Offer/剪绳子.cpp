class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return int整型
     */
    
    int cutRope(int n) {
        // write code here
        if(n == 2 || n == 3) return n-1;
        int res = 1;
        while(n>4)
        {
            n-=3;
            res *=3;
        }
        return n*res;
    }
};
