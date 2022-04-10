class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return int整型
     */
    int back_track(int n,vector<int> &mark)
    {
        // n<=4
        if(n<=4) return n;
        
        // 记忆化搜索
        if(mark[n] != -1)
        {
            return mark[n];
        }
        
        int ret = 0;
        for(int i=1;i<n;++i)
        {
            ret = max(ret,i*back_track(n-i,mark));
        }
        
        // 添加进mark啊
        return mark[n] = ret;
    }
    
    int cutRope(int n) {
        // write code here
        if(n == 2) return 1;
        if(n == 3) return 2;
        
        // 记忆化搜索部分
        vector<int> mark(n+1,-1);
        return back_track(n,mark);
        
    }
};
