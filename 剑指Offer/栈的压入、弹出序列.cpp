class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        // 原地栈（扩展思路）
        // 感觉这个厉害啊！！！
        
        
        //表示栈空间的大小，初始化为0
        int n=0;
        //出栈序列的下标
        int j=0;
        //对于每个待入栈的元素
        for(auto num:pushV)
        {
            //加入栈顶
            pushV[n] = num;
            //当栈不为空且栈顶等于当前出栈序列
            while(n>=0 && pushV[n] == popV[j])
            {
                j++;
                n--;
            }
            n++;
        }
        //最后的栈是否为空
        return n == 0;
    }
};
