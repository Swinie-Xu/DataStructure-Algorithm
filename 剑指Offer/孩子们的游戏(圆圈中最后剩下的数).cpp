class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        // 所谓约瑟夫环，可是递推过程我没看懂
        // 记住？？？
        
        /*
            公式递推：
            令f(n,m)表示最后一个人的下标。
            1.假设有n个人，报数m， 从0 开始报数，易知出圈的人下标为 m-1。
            2.m-1 出圈后，我们对剩余人重新编号 即 第m个人下标为0，第m+1 下标为1 ......以此编号。 那么重新编号之后，那么最后一个人的下标为f(n-1,m)
            问题1： 在重新编号之后的f(n-1,m) 与 重新编号之前的f(n,m)有什么关系？
            重新编号之前 m, m+1,m+2,....
            重新编号之后 0 ，1 ，2，....
            可知 (新编号+m)%n = 旧编号
            3. f(n,m) = (f(n-1,m)+m) %n;
        */
        
        if(n<1||m<1) return -1;
        int last = 0;
        for(int i=2;i<=n;++i)
            last = (last+m)%i;
        return last;
        
        
        /*
        // 递归的版本，这个厉害了啊
        
        class Solution {
        public:
            //约瑟夫
            int LastRemaining_Solution(int n, int m) {
                if(n <= 0) return -1;
                return (LastRemaining_Solution(n-1,m)+m)%n;
            }
        };
        */

    }
};
