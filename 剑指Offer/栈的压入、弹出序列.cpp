class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        // 照着解答自己没写出来，看着参考代码写的
        // 感觉早上逻辑不清楚啊，咋回事
        int n = pushV.size();
        stack<int> s;//辅助栈
        int j = 0;//遍历入栈的下标
        for(int i=0;i<n;i++)//遍历出栈的数组
        {
            //入栈：栈为空或者栈顶不等于出栈数组
            while(j<n && (s.empty() || s.top()!=popV[i]))
            {
                s.push(pushV[j]);
                j++;
            }
            // 自己写的时候一直找不到出口，其实只要没办法
            // 按照特定顺序走完，就可以判断false了！
            if(s.top() == popV[i]) s.pop(); //栈顶等于出栈数组
            else return false;//不匹配序列
        }
        return true;
    }
};
